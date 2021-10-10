#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

#include "Triangle_Mesh.h"
#include "Square_Mesh.h"
#include "Hexagon_Mesh.h"
#include "Expectations.h"
#include "Shader.h"
#include "Colored_2D_Shader_Program.h"
#include "textured_2D_shader_program.h"
#include "texture.h"

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

	// CPU CODE: C++ -- VS Compiles -- > -- Windows run via CPU
	// CPU CODE: GLSL -- OpenGL Compiles -- > -- OpenGL run via GPU

	// Colours for each vertex
	std::vector<GLfloat> colors =
	{
		1.0f, 0.5f, 0.0f, 1.0f, // v1 
		1.0f, 1.0f, 0.0f, 1.0f, // v2 
		1.0f, 0.5f, 0.0f, 1.0f, // v3	 

		1.0f, 0.5f, 0.0f, 1.0f, // v4 
		1.0f, 0.5f, 0.0f, 1.0f, // v5 
		1.0f, 1.0f, 0.0f, 1.0f, // v6

		1.0f, 0.5f, 0.0f, 1.0f, // v7
		1.0f, 0.5f, 0.0f, 1.0f, // v8  
		1.0f, 1.0f, 0.0f, 1.0f, // v9  

		1.0f, 1.0f, 0.0f, 1.0f, // v10 
		1.0f, 0.5f, 0.0f, 1.0f, // v11 
		1.0f, 0.5f, 0.0f, 1.0f, // v12  

		1.0f, 1.0f, 0.0f, 1.0f, // v13 
		1.0f, 0.5f, 0.0f, 1.0f, // v14  
		1.0f, 0.5f, 0.0f, 1.0f, // v15 

		1.0f, 0.5f, 0.0f, 1.0f, // v16 
		1.0f, 1.0f, 0.0f, 1.0f, // v17  
		1.0f, 0.5f, 0.0f, 1.0f, // v18 
	};							
	
	Hexagon_Mesh* hexagon = new Hexagon_Mesh();

	Shader* vertex_shader = new Shader("Shaders/colored.2D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* fragment_shader = new Shader("Shaders/colored.2D.fragment_shader.glsl", Shader::Type::Fragment);
	Colored_2D_Shader_Program* program = new Colored_2D_Shader_Program(vertex_shader, fragment_shader);

	/*Shader* vertex_shader = new Shader("Shaders/textured.2D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* fragment_shader = new Shader("Shaders/textured.2D.fragment_shader.glsl", Shader::Type::Fragment);
	Textured_2D_Shader_Program* program = new Textured_2D_Shader_Program(vertex_shader, fragment_shader);
	Texture* texture = new Texture("Assets/sprite.airplane.png");*/

	while (true)
	{
		program->render(hexagon, &colors);

		glfwSwapBuffers(window);
		glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(0);
		glUseProgram(0);
	}
}