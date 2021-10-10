#include "textured_2D_shader_program.h"
#include "Mesh.h"
#include "Expectations.h"

Textured_2D_Shader_Program::Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program(vertex_shader, fragment_shader)
{
}
Textured_2D_Shader_Program::~Textured_2D_Shader_Program()
{
}

void Textured_2D_Shader_Program::render(const Mesh* mesh, const Texture* texture) const
{
	// Use this program
	glUseProgram(program());
	glBindVertexArray(vao());

	// Create a buffer and fill with vertex data.
	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	// Associate 'vertex_position' with the buffer.
	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	// Create a buffer for tex_coords.
	GLuint tbo_index;
	glGenBuffers(1, &tbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, tbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->texture_coordinates().size(), mesh->texture_coordinates().data(), GL_STATIC_DRAW);

	// Associate 'vertex_texture_coordinates' with the buffer.
	GLint texture_coordinate_location = glGetAttribLocation(program(), "vertex_texture_coordinate");
	expect(texture_coordinate_location != -1, "Failed to get texture_coordinate_location");
	glEnableVertexAttribArray(texture_coordinate_location);
	glVertexAttribPointer(texture_coordinate_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	// Generate a texture.
	GLuint texture_location;
	glGenTextures(1, &texture_location);

	// Set that texture as our focus.
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture_location);

	// Assign some data with the texture.
	// Repeat the image over and over.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// We put the texture data onto the GPU.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width(), texture->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, texture->data());

	// Associate 'image' with the current image (0).
	GLint image_location = glGetUniformLocation(program(), "image");
	expect(image_location != -1, "Failed to find image uniform location.");
	glUniform1i(image_location, 0); // the first texture is 0.

	// TODO draw line loop (for fun)
	glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));

	glDeleteBuffers(1, &vbo_index);
	glDeleteTextures(1, &texture_location);
}