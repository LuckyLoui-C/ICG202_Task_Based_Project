#pragma once

#include "obj_file_mesh.h"
#include "Expectations.h"

#include <fstream>
#include <string>
#include <sstream>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

Obj_File_Mesh::Obj_File_Mesh(const char* file_path)
	: Mesh()
{
	std::ifstream file(file_path);
expect(file.is_open(), (std::string("Failed to open file. File: ") + file_path).c_str());

std::vector<glm::vec3> verticies;
std::vector<glm::vec2> texture_coordinates;
std::vector<glm::vec3> normals;

std::vector<unsigned int> vertex_indicies;
std::vector<unsigned int> texture_coordinate_indicies;
std::vector<unsigned int> normal_indicies;

std::string line;
while(std::getline(file, line))
{
	if(line.substr(0, 2) == "vt")
	{
		const size_t size = texture_coordinates.size();
		texture_coordinates.resize(size + 1);

		std::istringstream ss(line.substr(3));
		ss >> texture_coordinates.data()[size].x >> texture_coordinates.data()[size].y;
	}
	/*
	else if(line.substr(0, 2) == "vn")
	{
		const size_t size = normals.size();
		normals.resize(size + 1);

		std::istringstream ss(line.substr(3));
		ss >> normals.data()[size].x >> normals.data()[size].y >> normals.data()[size].z;
	}
	*/
	else if(line[0] == 'v')
	{
		const size_t size = verticies.size();
		verticies.resize(size + 1);

		std::istringstream ss(line.substr(2));
		ss >> verticies.data()[size].x >> verticies.data()[size].y >> verticies.data()[size].z;
	}
	else if(line[0] == 'f')
	{
		//unsigned int vertex_indicies[3], texture_coordinate_indicies[3], normal_indicies[3];

		std::istringstream ss(line.substr(2));
		while(ss.good())
		{
			const size_t size = vertex_indicies.size();
			vertex_indicies.resize(size + 1);
			texture_coordinate_indicies.resize(size + 1);
			normal_indicies.resize(size + 1);

			char seperator;

			ss >> vertex_indicies.data()[size] >> seperator >> texture_coordinate_indicies.data()[size] >> seperator >> normal_indicies.data()[size];
		}

	}
}

for(int index = 0; index < vertex_indicies.size(); ++index)
{
	int vertex_index = vertex_indicies[index] - 1;
	glm::vec3 vertex = verticies[vertex_index];
	_verticies.push_back(vertex.x);
	_verticies.push_back(vertex.y);
	_verticies.push_back(vertex.z);
}

for(int index = 0; index < texture_coordinate_indicies.size(); ++index)
{
	int texture_coordinate_index = texture_coordinate_indicies[index] - 1;
	glm::vec2 texture_coordinate = texture_coordinates[texture_coordinate_index];
	_texture_coordinates.push_back(texture_coordinate.x);
	_texture_coordinates.push_back(texture_coordinate.y);
}
}
Obj_File_Mesh::~Obj_File_Mesh()
{
}