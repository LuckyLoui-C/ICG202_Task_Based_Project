#pragma once

#include "Shader_Program.h"
#include <glm/mat4x4.hpp>
#include <vector>

class Mesh;
struct Configuration;

class Colored_3D_Shader_Program : public Shader_Program
{
public:
	Colored_3D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Colored_3D_Shader_Program();

	void render(const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* transformation) const;
};