#pragma once

#include <string>

#define GLEW_STATIC
#include <glew.h>

class Shader;

class Shader_Program
{
public:
	Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Shader_Program();

	const GLuint program() const;
	const GLuint vao() const;

private:
	GLuint _program;
	GLuint _vao;
};

