#include "Colored_2D_Shader_Program.h"
#include "Mesh.h"
#include "Expectations.h"

#include <iostream>

Colored_2D_Shader_Program::Colored_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program(vertex_shader, fragment_shader)
{
}

Colored_2D_Shader_Program::~Colored_2D_Shader_Program()
{
}

void Colored_2D_Shader_Program::render(const Mesh* mesh, const std::vector<GLfloat>* colors) const
{
	glUseProgram(program()); // Installs a program object, part of current rendering state
	glBindVertexArray(vao());

	// Input vertex data to GPU
	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	// In the shader -> associate the variable vertex_position with the vertex data
	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint cbo_index;
	glGenBuffers(1, &cbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, cbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * colors->size(), colors->data(), GL_STATIC_DRAW);

	// 12 floats, RGBA for each 3 vertices
	GLint color_location = glGetAttribLocation(program(), "vertex_color");
	expect(color_location != -1, "Failed to get color_location");
	glEnableVertexAttribArray(color_location);
	glVertexAttribPointer(color_location, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// Draw the arrays
	glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));

	// Delete the arrays
	glDeleteBuffers(1, &vbo_index);

	glUseProgram(0);
}