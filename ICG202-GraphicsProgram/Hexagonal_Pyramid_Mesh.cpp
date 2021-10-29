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

	auto t1 = { 1.0f, 1.0f }; // TR of image
	auto t2 = { 1.0f, 0.0f }; // BR of image
	auto t3 = { 0.0f, 0.0f }; // BL of image
	auto t4 = { 0.0f, 1.0f }; // TL of image
	auto t5 = { 0.5f, 1.0f }; // TM of image

	// HEXAGON BASE
	{
		// T1:
		_verticies.insert(_verticies.end(), v[6]); // 1
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[0]); // 2
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[1]); // 3
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		// T2:
		_verticies.insert(_verticies.end(), v[6]); // 4
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[5]); // 5
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		_verticies.insert(_verticies.end(), v[0]); // 6
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		// T3
		_verticies.insert(_verticies.end(), v[5]); // 7
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[4]); // 8 
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		_verticies.insert(_verticies.end(), v[0]); // 9
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		// T4
		_verticies.insert(_verticies.end(), v[0]); // 10
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[4]); // 11
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		_verticies.insert(_verticies.end(), v[3]); // 12
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		// T5
		_verticies.insert(_verticies.end(), v[0]); // 13
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[3]); // 14
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[2]); // 15
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		// T6
		_verticies.insert(_verticies.end(), v[1]); // 16
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[0]); // 17
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[2]); // 18
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
	}

	// TRIANGLE SIDE FACES
	{
		// Triangle Side 1 - 3rd vertex is not '1 - 1' so have to do manually
		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t5);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		/*
		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t3);

		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t3);

		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t4);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t1);

		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t3);

		_verticies.insert(_verticies.end(), v[1]); // v19
		_texture_coordinates.insert(_texture_coordinates.end(), t1);
		_verticies.insert(_verticies.end(), v[7]); // v20
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		_verticies.insert(_verticies.end(), v[6]); // v21
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
		*/

		// Create next 5 triangles automatically - Can not use effectively with UV mapping (yet)
		for (int i = 2; i <= 7; i++)
		{
			_verticies.insert(_verticies.end(), v[i]); // v
		_texture_coordinates.insert(_texture_coordinates.end(), t3);
			_verticies.insert(_verticies.end(), v[7]); // v
		_texture_coordinates.insert(_texture_coordinates.end(), t5);
			_verticies.insert(_verticies.end(), v[(i - 1)]); // 
		_texture_coordinates.insert(_texture_coordinates.end(), t2);
		}
	}
}

Hexagonal_Pyramid_Mesh::~Hexagonal_Pyramid_Mesh()
{
}