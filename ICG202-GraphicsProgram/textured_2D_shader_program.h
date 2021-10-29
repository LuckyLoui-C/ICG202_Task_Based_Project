#pragma once

#include "Shader_Program.h"
#include "Texture.h"

#include <vector>
#include <glm/mat4x4.hpp>
 
class Mesh;

class Textured_2D_Shader_Program : public Shader_Program
{
public:
	Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Textured_2D_Shader_Program();

	void render(const Mesh* mesh, const Texture* texture, const Texture* mask, const glm::mat4* transformation) const;
};