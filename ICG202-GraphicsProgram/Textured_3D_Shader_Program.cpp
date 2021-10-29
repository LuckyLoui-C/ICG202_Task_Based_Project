#include "Textured_3D_Shader_Program.h"
#include "Mesh.h"
#include "Expectations.h"

Textured_3D_Shader_Program::Textured_3D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program(vertex_shader, fragment_shader)
{
}

Textured_3D_Shader_Program::~Textured_3D_Shader_Program()
{
}

void Textured_3D_Shader_Program::render(const Mesh* mesh, const Texture* texture, const glm::mat4* transformation) const
{
	glUseProgram(program());
	glBindVertexArray(vao());

	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	GLint transformation_location = glGetUniformLocation(program(), "transformation");
	expect(transformation_location != -1, "Failed to find mask uniform location.");
	glUniformMatrix4fv(transformation_location, 1, GL_FALSE, &(*transformation)[0][0]);

	GLuint tbo_index;
	glGenBuffers(1, &tbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, tbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->texture_coordinates().size(), mesh->texture_coordinates().data(), GL_STATIC_DRAW);

	GLint vertex_texture_coordinate_location = glGetAttribLocation(program(), "vertex_texture_coordinate");
	expect(vertex_texture_coordinate_location != -1, "Failed to get vertex_texture_coordinate_location");
	glEnableVertexAttribArray(vertex_texture_coordinate_location);
	glVertexAttribPointer(vertex_texture_coordinate_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint texture_location;
	glGenTextures(1, &texture_location);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture_location);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width(), texture->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, texture->data());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLint image_location = glGetUniformLocation(program(), "image");
	expect(image_location != -1, "Failed to find image uniform location.");
	glUniform1i(image_location, 0);

	glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));

	glDeleteBuffers(1, &vbo_index);
	glDeleteTextures(1, &texture_location);
}