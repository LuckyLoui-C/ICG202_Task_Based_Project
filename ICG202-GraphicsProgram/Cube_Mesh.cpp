#pragma once;
#include "Cube_Mesh.h"

Cube_Mesh::Cube_Mesh()
{
	auto v1 = { 0.5f, 0.5f, -0.5f }; // TR FF
	auto v2 = { 0.5f, -0.5f, -0.5f }; // BR FF
	auto v3 = { -0.5f, -0.5f, -0.5f }; // BL FF
	auto v4 = { -0.5f, 0.5f, -0.5f }; // TL FF

	auto v5 = { 0.5f, 0.5f, 0.5f }; // TR FF
	auto v6 = { 0.5f, -0.5f, 0.5f }; // BR FF
	auto v7 = { -0.5f, -0.5f, 0.5f }; // BL FF
	auto v8 = { -0.5f, 0.5f, 0.5f }; // TL FF

	// Front face
	// triangle 1
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v3);
	// triangle 2
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v1);

	// Back face
	// triangle 1
	_verticies.insert(_verticies.end(), v8);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v6);
	// triangle 2
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v8);

	// Bottom Face
	// triangle 1
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v7);
	// triangle two
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v2);

	// Top Face
	// triangle 1
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v4);
	// triangle two
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v8);
	_verticies.insert(_verticies.end(), v5);
	
	// Left Face
	// triangle 1
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v7);
	// triangle two
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v8);
	_verticies.insert(_verticies.end(), v4);

	// Right Face
	// triangle 1
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v2);
	// triangle two
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v5);
}

Cube_Mesh::~Cube_Mesh()
{
}