#include "Square_Mesh.h"

Square_Mesh::Square_Mesh() : Mesh()
{
	_verticies.insert(_verticies.end(), { 0.7, 0.7f }); // TR
	_verticies.insert(_verticies.end(), { 0.7f, -0.7f }); // BR
	_verticies.insert(_verticies.end(), { -0.7f, -0.7f }); // BL

	_verticies.insert(_verticies.end(), { -0.7f, -0.7f }); // BL
	_verticies.insert(_verticies.end(), { -0.7f, 0.7f }); // TL
	_verticies.insert(_verticies.end(), { 0.7, 0.7f }); // TR

	_texture_coordinates.insert(_texture_coordinates.end(), { 1,1 }); // TR
	_texture_coordinates.insert(_texture_coordinates.end(), { 1,0 }); // BR
	_texture_coordinates.insert(_texture_coordinates.end(), { 0,0 }); // BL

	_texture_coordinates.insert(_texture_coordinates.end(), { 0,0 }); // BL
	_texture_coordinates.insert(_texture_coordinates.end(), { 0,1 }); // TL
	_texture_coordinates.insert(_texture_coordinates.end(), { 1,1 }); // TR
}

Square_Mesh::~Square_Mesh()
{
}