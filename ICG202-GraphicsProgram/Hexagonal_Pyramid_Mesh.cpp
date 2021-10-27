#pragma once
#include "Hexagonal_Pyramid_Mesh.h"

Hexagonal_Pyramid_Mesh::Hexagonal_Pyramid_Mesh()
{
	std::initializer_list<GLfloat> v[8]; // Used to auto-generate faces

	v[0] = { 0.0f, -0.5f, 0.0f };
	v[1] = { -0.3f, -0.5f, -0.6f };
	v[2] = { -0.6f, -0.5f, 0.0f };
	v[3] = { -0.3f, -0.5f, 0.6f };
	v[4] = { 0.3f, -0.5f, 0.6f };
	v[5] = { 0.6f, -0.5f, 0.0f };
	v[6] = { 0.3f, -0.5f, -0.6f };
	v[7] = { 0.0f, 0.6f, 0.0f };

	// HEXAGON BASE
	{
		// T1:
		_verticies.insert(_verticies.end(), v[6]); // 1
		_verticies.insert(_verticies.end(), v[0]); // 2
		_verticies.insert(_verticies.end(), v[1]); // 3
		// T2:
		_verticies.insert(_verticies.end(), v[6]); // 4
		_verticies.insert(_verticies.end(), v[5]); // 5
		_verticies.insert(_verticies.end(), v[0]); // 6
		// T3
		_verticies.insert(_verticies.end(), v[5]); // 7
		_verticies.insert(_verticies.end(), v[4]); // 8 
		_verticies.insert(_verticies.end(), v[0]); // 9
		// T4
		_verticies.insert(_verticies.end(), v[0]); // 10
		_verticies.insert(_verticies.end(), v[4]); // 11
		_verticies.insert(_verticies.end(), v[3]); // 12
		// T5
		_verticies.insert(_verticies.end(), v[0]); // 13
		_verticies.insert(_verticies.end(), v[3]); // 14
		_verticies.insert(_verticies.end(), v[2]); // 15
		// T6
		_verticies.insert(_verticies.end(), v[1]); // 16
		_verticies.insert(_verticies.end(), v[0]); // 17
		_verticies.insert(_verticies.end(), v[2]); // 18
	}

	// TRIANGLE SIDE FACES
	{
		// Triangle Side 1 - 3rd vertex is not '1 - 1' so have to do manually
		_verticies.insert(_verticies.end(), v[1]); // v19
		_verticies.insert(_verticies.end(), v[7]); // v20
		_verticies.insert(_verticies.end(), v[6]); // v21

		// Create next 5 triangles automatically
		for (int i = 2; i <= 7; i++)
		{
			_verticies.insert(_verticies.end(), v[i]); // v
			_verticies.insert(_verticies.end(), v[7]); // v
			_verticies.insert(_verticies.end(), v[(i - 1)]); // 
		}
	}
}

Hexagonal_Pyramid_Mesh::~Hexagonal_Pyramid_Mesh()
{
}