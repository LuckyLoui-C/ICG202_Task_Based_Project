#pragma once
#include "Shader_Program.h"
#include "texture.h"

#include <glm/mat4x4.hpp>
#include <vector>

class Mesh;


class Textured_Lit_Light_3D_Shader_Program : public Shader_Program
{
public:
	Textured_Lit_Light_3D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Textured_Lit_Light_3D_Shader_Program();

	void render(const Mesh* mesh, const Texture* texture, const glm::mat4* transformation) const;
};