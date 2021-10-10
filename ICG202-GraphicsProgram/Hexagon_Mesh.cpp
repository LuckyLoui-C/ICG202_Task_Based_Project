#pragma once
#include "Hexagon_Mesh.h"
#include "Triangle_Mesh.h"

Hexagon_Mesh::Hexagon_Mesh() : Mesh()
{
	// Clockwise ordered
	// Triangle 1:
	_verticies.insert(_verticies.end(), { -0.3f, -0.6f }); // v1
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // v2
	_verticies.insert(_verticies.end(), { 0.3f, -0.6f }); // v3	

	// Rest of hexagon:
	_verticies.insert(_verticies.end(), { -0.3f, -0.6f }); // 4
	_verticies.insert(_verticies.end(), { -0.6f, 0.0f }); // 5
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // 6

	_verticies.insert(_verticies.end(), { -0.6f, 0.0f }); // 7
	_verticies.insert(_verticies.end(), { -0.3f, 0.6f }); // 8
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // 9

	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // 10
	_verticies.insert(_verticies.end(), { -0.3f, 0.6f }); // 11
	_verticies.insert(_verticies.end(), { 0.3f, 0.6f }); // 12

	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // 13
	_verticies.insert(_verticies.end(), { 0.3f, 0.6f }); // 14
	_verticies.insert(_verticies.end(), { 0.6f, 0.0f }); // 15

	_verticies.insert(_verticies.end(), { 0.3f, -0.6f }); // 16
	_verticies.insert(_verticies.end(), { 0.0f, 0.0f }); // 17
	_verticies.insert(_verticies.end(), { 0.6f, 0.0f }); // 18
}

Hexagon_Mesh::~Hexagon_Mesh()
{
}