#pragma once
#include "Hexagon_Mesh.h"

Hexagon_Mesh::Hexagon_Mesh() : Mesh()
{
	auto v0 = { 0.0f, 0.0f, -0.5f };   // 0
	auto v1 = { -0.3f, -0.6f, -0.5f }; // 1
	auto v2 = { -0.6f, 0.0f, -0.5f };  // 2
	auto v3 = { -0.3f, 0.6f, -0.5f };  // 3
	auto v4 = { 0.3f, 0.6f, -0.5f };   // 4
	auto v5 = { 0.6f, 0.0f, -0.5f };   // 5
	auto v6 = { 0.3f, -0.6f, -0.5f };   // 6
	
	// Clockwise ordered
	// Triangle 1:
	_verticies.insert(_verticies.end(), v1); // 1
	_verticies.insert(_verticies.end(), v0); // 2
	_verticies.insert(_verticies.end(), v6); // 3
	// T2:
	_verticies.insert(_verticies.end(), v1); // 4
	_verticies.insert(_verticies.end(), v2); // 5
	_verticies.insert(_verticies.end(), v0); // 6
	// T3
	_verticies.insert(_verticies.end(), v2); // 7
	_verticies.insert(_verticies.end(), v3); // 8 
	_verticies.insert(_verticies.end(), v0); // 9
	// T4
	_verticies.insert(_verticies.end(), v0); // 10
	_verticies.insert(_verticies.end(), v3); // 11
	_verticies.insert(_verticies.end(), v4); // 12
	// T5
	_verticies.insert(_verticies.end(), v0); // 13
	_verticies.insert(_verticies.end(), v4); // 14
	_verticies.insert(_verticies.end(), v5); // 15
	// T6
	_verticies.insert(_verticies.end(), v6); // 16
	_verticies.insert(_verticies.end(), v0); // 17
	_verticies.insert(_verticies.end(), v5); // 18
}

Hexagon_Mesh::~Hexagon_Mesh()
{
}