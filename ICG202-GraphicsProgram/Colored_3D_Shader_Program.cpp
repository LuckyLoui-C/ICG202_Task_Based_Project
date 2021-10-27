#include "Colored_3D_Shader_Program.h"
#include "Mesh.h"
#include "Expectations.h"

Colored_3D_Shader_Program::Colored_3D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program(vertex_shader, fragment_shader)
{
}
Colored_3D_Shader_Program::~Colored_3D_Shader_Program()
{
}

void Colored_3D_Shader_Program::render(const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* transformation) const
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

	GLuint cbo_index;
	glGenBuffers(1, &cbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, cbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * colors->size(), colors->data(), GL_STATIC_DRAW);

	GLint color_location = glGetAttribLocation(program(), "vertex_color");
	expect(color_location != -1, "Failed to get color_location");
	glEnableVertexAttribArray(color_location);
	glVertexAttribPointer(color_location, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));

	glDeleteBuffers(1, &vbo_index);
	glDeleteBuffers(1, &cbo_index);
}
