 #pragma once
#include "Triangle_Mesh.h"

Triangle_Mesh::Triangle_Mesh() : Mesh()
{
	// These are clockwise ordered
	_verticies.insert(_verticies.end(), { -0.5f, -0.5f }); // v1
	_verticies.insert(_verticies.end(), { 0.0f, 0.5f }); // v2
	_verticies.insert(_verticies.end(), { 0.5f, -0.5f }); // v3
}
Triangle_Mesh::~Triangle_Mesh()
{
}