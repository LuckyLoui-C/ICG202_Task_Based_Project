#pragma once

#include <string>

#define GLEW_STATIC
#include <glew.h>

class Shader
{
public:
	enum class Type
	{
		Vertex,
		Fragment
	};

	Shader(const char* file_path, const Type type);
	~Shader();

	const GLuint data() const;

private:
	GLuint _data;
};