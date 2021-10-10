#pragma once

#include "Shader_Program.h"
#include "texture.h"

#include <vector>

class Mesh;

class Textured_2D_Shader_Program : public Shader_Program
{
public:
	Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Textured_2D_Shader_Program();

	void render(const Mesh* mesh, const Texture* texture) const;
};