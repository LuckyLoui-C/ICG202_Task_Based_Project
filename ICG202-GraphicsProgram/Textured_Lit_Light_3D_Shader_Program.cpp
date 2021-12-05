#include "Textured_Lit_Light_3D_Shader_Program.h"
#include "Mesh.h"
#include "Expectations.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <iostream>

Textured_Lit_Light_3D_Shader_Program::Textured_Lit_Light_3D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program(vertex_shader, fragment_shader)
{
}

Textured_Lit_Light_3D_Shader_Program::~Textured_Lit_Light_3D_Shader_Program()
{
}

void Textured_Lit_Light_3D_Shader_Program::render(const Mesh* mesh, const Texture* texture, const glm::mat4* transformation) const
{

	static std::default_random_engine generator;
	static std::uniform_real_distribution<float> distribution(0.f, 1.0f);
	float dice_roll1 = distribution(generator);
	float dice_roll2 = distribution(generator);
	float dice_roll3 = distribution(generator);

	static float a = 0.5f;
	static float b = 0.4f;

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

	GLuint normal_index;
	glGenBuffers(1, &normal_index);
	glBindBuffer(GL_ARRAY_BUFFER, normal_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->normals().size(), mesh->normals().data(), GL_STATIC_DRAW);

	GLint normal_location = glGetAttribLocation(program(), "vertex_normal");
	expect(normal_location != -1, "Failed to get normal_location");
	glEnableVertexAttribArray(normal_location);
	glVertexAttribPointer(normal_location, 3, GL_FLOAT, GL_FALSE, 0, NULL);

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
	
	/*
	GLint lighting_color_location = glGetUniformLocation(program(), "lighting_color");
	expect(lighting_color_location != -1, "Failed to find lighting_color uniform location.");
	glUniform3f(lighting_color_location, 0.8f, 0.5f, 0.15f);
	*/

	GLint lighting_position_location = glGetUniformLocation(program(), "lighting_position");
	expect(lighting_position_location != -1, "Failed to find lighting_position uniform location.");
	glUniform3f(lighting_position_location, 0.0f, 0.0f, -1.0f);
	
	/*
	GLint lighting_brightness_location = glGetUniformLocation(program(), "lighting_brightness");
	expect(lighting_brightness_location != -1, "Failed to find lighting_brightness uniform location.");
	glUniform1f(lighting_brightness_location, (sinf(a) + cos(b)));
	*/
	a += 0.0f; 
	b += 0.5;

	glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));

	glDeleteBuffers(1, &vbo_index);
	//glDeleteTextures(1, &texture_location);
}