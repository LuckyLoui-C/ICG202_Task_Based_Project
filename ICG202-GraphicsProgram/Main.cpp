#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>
#include <math.h>
#include <time.h>

#include "Triangle_Mesh.h"
#include "Square_Mesh.h"
#include "Hexagon_Mesh.h"
#include "Expectations.h"
#include "Shader.h"
#include "Colored_2D_Shader_Program.h"
#include "textured_2D_shader_program.h"
#include "Colored_3D_Shader_Program.h"
#include "texture.h"
#include "Cube_Mesh.h"
#include "Hexagonal_Pyramid_Mesh.h"

void gl_debug_message_callback(GLenum, GLenum type, GLuint, GLenum severity,
	GLsizei, const GLchar * message, const void*)
{
	if (severity > GL_DEBUG_SEVERITY_NOTIFICATION)
	{
		fprintf(stderr, "GL_CALBACK: %S type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
		std::cout << glGetError() << std::endl;
	}
}

int main(void)
{
	expect(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(1200, 860, "ICG202 - Hexagon Render", NULL, NULL);
	expect(window != nullptr, "Failed to create GLFW window!");
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	const GLenum init_result = glewInit();
	expect(glewInit() == GLEW_OK, (char*)glewGetErrorString(init_result));

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(gl_debug_message_callback, 0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	// CPU CODE: C++ -- VS Compiles -- > -- Windows run via CPU
	// CPU CODE: GLSL -- OpenGL Compiles -- > -- OpenGL run via GPU

							
	
	//Square_Mesh* square = new Square_Mesh(); // Square to be filled with colour or texture
	//Shader* vertex_shader = new Shader("Shaders/textured.2D.vertex_shader.glsl", Shader::Type::Vertex);
	//Shader* fragment_shader = new Shader("Shaders/textured.2D.fragment_shader.glsl", Shader::Type::Fragment);
	//Textured_2D_Shader_Program* program = new Textured_2D_Shader_Program(vertex_shader, fragment_shader);
	//Texture* texture = new Texture("Assets/sprite.airplane.png");
	//Texture* mask = new Texture("Assets/mask.airplane_background.png");

	// Colours for each vertex
	std::vector<GLfloat> colors =
	{
		// Front Face - Red
		// triangle 1
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 2
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,

		// Back Face - Blue-Green	 
		// triangle 1
		0.0f, 0.5f, 0.5f, 1.0f,
		0.0f, 0.5f, 0.5f, 1.0f,
		0.0f, 0.5f, 0.5f, 1.0f,
		// triangle 2
		0.0f, 0.5f, 0.5f, 1.0f,
		0.0f, 0.5f, 0.5f, 1.0f,
		0.0f, 0.5f, 0.5f, 1.0f,

		// Bottom Face - Purple
		// triangle 1
		0.120f, 0.13f, 0.200f, 1.0f,
		0.120f, 0.13f, 0.200f, 1.0f,
		0.120f, 0.13f, 0.200f, 1.0f,
		// triangle 2
		0.120f, 0.13f, 0.200f, 1.0f,
		0.120f, 0.13f, 0.200f, 1.0f,
		0.120f, 0.13f, 0.200f, 1.0f,

		// Top Face - Yellow
		// triangle 1
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		// triangle 2
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,

		// Left Face - Blue
		// triangle 1
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		// triange 2
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

		// Right Face - Brown
		// triangle 1
		0.5f, 0.2f, 0.0f, 1.0f,
		0.5f, 0.2f, 0.0f, 1.0f,
		0.5f, 0.2f, 0.0f, 1.0f,
		// triange 2  
		0.5f, 0.2f, 0.0f, 1.0f,
		0.5f, 0.2f, 0.0f, 1.0f,
		0.5f, 0.2f, 0.0f, 1.0f,


	};
	std::vector<GLfloat> hexagon_colors =
	{
		// HEXAGON BASE COLORS
		// triangle 1
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 2
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
		// triangle 3
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 4
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
		// triangle 5
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 6
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
		1.0f, 0.9f, 0.200f, 1.0f,
	};
	std::vector<GLfloat> hexagonal_pyramid_colors =
	{
		// HEXAGON BASE COLORS
		// triangle 1
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 2
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 3
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 4
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 5
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		// triangle 6
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,

		// TRIANGULAR SIDE FACE COLORS
		// Triangle Face 1
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
		// Triangle Face 2
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
		// Triangle Face 3
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
		// Triangle Face 4
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
		// Triangle Face 5
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
		// Triangle Face 6
		0.0f, 0.0f, 0.5f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.1f, 1.0f,
	};

	Cube_Mesh* cube = new Cube_Mesh();
	Shader* vertex_shader = new Shader("Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* fragment_shader = new Shader("Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Colored_3D_Shader_Program* program = new Colored_3D_Shader_Program(vertex_shader, fragment_shader);

	/*Hexagon_Mesh* hexagon = new Hexagon_Mesh();
	Shader* hexagon_vertex_shader = new Shader("Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* hexagon_fragment_shader = new Shader("Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Colored_3D_Shader_Program* hexagon_program = new Colored_3D_Shader_Program(hexagon_vertex_shader, hexagon_fragment_shader);*/

	Hexagonal_Pyramid_Mesh* hexagonal_pyramid_mesh = new Hexagonal_Pyramid_Mesh();
	Shader* pyramid_vertex_shader = new Shader("Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* pyramid_fragment_shader = new Shader("Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Colored_3D_Shader_Program* pyramid_scheme = new Colored_3D_Shader_Program(pyramid_vertex_shader, pyramid_fragment_shader);

	// Re-use a mesh over and over
	// Transform a mesh using the GPU
	// CPU - floats, integers
	// GPU - matrix multiplication usin thousands of cores.
	 	
	float a = 0.0f;
	float b = 0.0f;
	float c = 0.0f;
	float d = 0.0f;
	while (true)
	{
		{
			glm::vec3 translation = glm::vec3(0.5f, 0.f, 0.f);
			glm::vec3 rotation = glm::vec3(a, b, 0.0f);
			glm::vec3 scale = glm::vec3(0.25f, 0.25f, 0.25f);

			glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

			glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
			glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
			glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;

			glm::mat4 model = translation_m * rotation_m * scale_m;

			program->render(cube, &colors, &model);
		}		
		{
			glm::vec3 translation = glm::vec3(-0.5f, 0.f, 0.0f);
			glm::vec3 rotation = glm::vec3(0.0f, a, 0.0f);
			glm::vec3 scale = glm::vec3(0.25f, 0.25f, 0.25f);

			glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

			glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
			glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
			glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;

			glm::mat4 model = translation_m * rotation_m * scale_m;

			pyramid_scheme->render(hexagonal_pyramid_mesh, &hexagonal_pyramid_colors, &model);
		}

		// This renders the objects to the scene
		glfwSwapBuffers(window);
		glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(0);
		glUseProgram(0);
		a += 0.01f;
		b += 0.02f;
		c += 0.2f;
		d += 0.004f;
	}
}