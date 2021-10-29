#pragma once
#include "Cheese_Wedge_Mesh.h"

Cheese_Wedge_Mesh::Cheese_Wedge_Mesh()
{
	// Verticies
	auto v1 = { 0.0f, 0.0f, 0.0f };
	auto v2 = { 0.0f, 1.0f, 0.0f };
	auto v3 = { 1.0f, 0.0f, 0.0f };
	auto v4 = { 0.0f, 0.0f, 1.0f };
	auto v5 = { 0.0f, 1.0f, 1.0f };
	auto v6 = { 1.0f, 0.0f, 1.0f };
	auto v7 = { 0.5f, 0.0f, 0.0f };
	auto v8 = { 0.5f, 0.0f, 1.0f };
	// Image verticies
	auto t1 = { 1.0f, 1.0f }; // TR of image
	auto t2 = { 1.0f, 0.0f }; // BR of image
	auto t3 = { 0.0f, 0.0f }; // BL of image
	auto t4 = { 0.0f, 1.0f }; // TL of image

	// Triangle Faces
	// T1
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// T2
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);

	// Square Faces
	// S1, T1
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// T2
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// S2, T1
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v5);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// T2
	_verticies.insert(_verticies.end(), v2);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);

	// Rectangle Face
	// S1, T1
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v1);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// T2
	_verticies.insert(_verticies.end(), v4);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	// S2, T1
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
	_verticies.insert(_verticies.end(), v7);
	_texture_coordinates.insert(_texture_coordinates.end(), t2);
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	// T2
	_verticies.insert(_verticies.end(), v8);
	_texture_coordinates.insert(_texture_coordinates.end(), t3);
	_verticies.insert(_verticies.end(), v6);
	_texture_coordinates.insert(_texture_coordinates.end(), t4);
	_verticies.insert(_verticies.end(), v3);
	_texture_coordinates.insert(_texture_coordinates.end(), t1);
}

Cheese_Wedge_Mesh::~Cheese_Wedge_Mesh()
{
}
