#pragma once;
#include "Cube_Mesh.h"

Cube_Mesh::Cube_Mesh()
{
	auto v1 = { 0.5f, 0.5f, -0.5f }; // TR FF
	auto v2 = { 0.5f, -0.5f, -0.5f }; // BR FF
	auto v3 = { -0.5f, -0.5f, -0.5f }; // BL FF
	auto v4 = { -0.5f, 0.5f, -0.5f }; // TL FF

	auto v5 = { 0.5f, 0.5f, 0.5f }; // TR BF
	auto v6 = { 0.5f, -0.5f, 0.5f }; // BR BF
	auto v7 = { -0.5f, -0.5f, 0.5f }; // BL BF
	auto v8 = { -0.5f, 0.5f, 0.5f }; // TL BF

	auto t1 = { 1.0f, 1.0f }; // TR of image
	auto t2 = { 1.0f, 0.0f }; // BR of image
	auto t3 = { 0.0f, 0.0f }; // BL of image
	auto t4 = { 0.0f, 1.0f }; // TL of image

	// Front face
	// triangle 1
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle 2
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// Back face
	// triangle 1
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle 2
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// Bottom Face
	// triangle 1
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle two
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// Top Face
	// triangle 1
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle two
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// Left Face
	// triangle 1
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle two
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// Right Face
	// triangle 1
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// triangle two
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
}

Cube_Mesh::~Cube_Mesh()
{
}