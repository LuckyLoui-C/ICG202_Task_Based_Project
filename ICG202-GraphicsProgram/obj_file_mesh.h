#pragma once

#include "Mesh.h"

class Obj_File_Mesh : public Mesh
{
public:
	Obj_File_Mesh(const char* file_path);
	~Obj_File_Mesh();
};
#pragma once