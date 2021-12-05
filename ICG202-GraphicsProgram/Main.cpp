#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>
#include <math.h>
#include <time.h>
#include <thread>
#include <chrono>

#include "Triangle_Mesh.h"
#include "Square_Mesh.h"
#include "Hexagon_Mesh.h"
#include "Expectations.h"
#include "Shader.h"
#include "Colored_2D_Shader_Program.h"
#include "textured_2D_shader_program.h"
#include "Colored_3D_Shader_Program.h"
#include "Textured_3D_Shader_Program.h"
#include "Textured_Lit_3D_Shader_Program.h"
#include "Textured_Lit_Horror_3D_Shader_Program.h"
#include "Textured_Lit_Light_3D_Shader_Program.h"
#include "texture.h"
#include "Cube_Mesh.h"
#include "Hexagonal_Pyramid_Mesh.h"
#include "Cheese_Wedge_Mesh.h"
#include "obj_file_mesh.h"

#define SCREEN_WIDTH 1500.0f
#define SCREEN_HEIGHT 1000.0f

enum Key_State
{
	RELEASED,
	PRESSED,
	HELD
};
Key_State escape_key_state = Key_State::RELEASED;
Key_State space_key_state = Key_State::RELEASED;
Key_State w_key_state = Key_State::RELEASED;
Key_State a_key_state = Key_State::RELEASED;
Key_State s_key_state = Key_State::RELEASED;
Key_State d_key_state = Key_State::RELEASED;
Key_State h_key_state = Key_State::RELEASED;
Key_State t_key_state = Key_State::RELEASED;

// OpenGL error calls this function
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

// Called on input
void on_input(GLFWwindow*, int key, int, int action, int)
{
	switch (action)
	{
		case GLFW_PRESS:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				escape_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_SPACE:
				space_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_W:
				w_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_A:
				a_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_S:
				s_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_D:
				d_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_H:
				h_key_state = Key_State::PRESSED;
				break;
			case GLFW_KEY_T:
				t_key_state = Key_State::PRESSED;
				break;
			}
			break;

		case GLFW_RELEASE:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				escape_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_SPACE:
				space_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_W:
				w_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_A:
				a_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_S:
				s_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_D:
				d_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_H:
				h_key_state = Key_State::RELEASED;
				break;
			case GLFW_KEY_T:
				t_key_state = Key_State::RELEASED;
				break;
			}
			break;
	};
}

double mouse_x_position = 0.0f;
double mouse_y_position = 0.0f;
double previous_mouse_x_position = 0.0f;
double previous_mouse_y_position = 0.0f;
int inputs_captured = 0;
void cursor_postion_callback(GLFWwindow* window, double xpos, double ypos)
{
	previous_mouse_x_position = mouse_x_position;
	previous_mouse_y_position = mouse_y_position;
	mouse_x_position = xpos;
	mouse_y_position = ypos;
	inputs_captured += 1;
}

int main(void)
{
	expect(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ICG202 - Hexagon Render", NULL, NULL);
	expect(window != nullptr, "Failed to create GLFW window!");
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	const GLenum init_result = glewInit();
	expect(glewInit() == GLEW_OK, (char*)glewGetErrorString(init_result));

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(gl_debug_message_callback, 0);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window, on_input);
	glfwSetCursorPosCallback(window, cursor_postion_callback);

	Shader* vertex_shader = new Shader("Shaders/textured.lit.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* fragment_shader = new Shader("Shaders/textured.lit.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Textured_Lit_3D_Shader_Program* program = new Textured_Lit_3D_Shader_Program(vertex_shader, fragment_shader);

	Shader* horror_vertex_shader = new Shader("Shaders/textured.lit.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* horror_fragment_shader = new Shader("Shaders/textured.lit.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Textured_Lit_Horror_3D_Shader_Program* horror_program = new Textured_Lit_Horror_3D_Shader_Program(horror_vertex_shader, horror_fragment_shader);

	Shader* light_vertex_shader = new Shader("Shaders/textured.light.3D.vertex_shader.glsl", Shader::Type::Vertex);
	Shader* light_fragment_shader = new Shader("Shaders/textured.light.3D.fragment_shader.glsl", Shader::Type::Fragment);
	Textured_Lit_Light_3D_Shader_Program* light_program = new Textured_Lit_Light_3D_Shader_Program(light_vertex_shader, light_fragment_shader);

	Cube_Mesh* mesh = new Cube_Mesh();
	Texture* texture = new Texture("Assets/texture.crate.jpg");

	Obj_File_Mesh* robot_mesh = new Obj_File_Mesh("Assets/robot.obj");
	Texture* robot_texture = new Texture("Assets/robot_diffuse.jpg");

	Hexagonal_Pyramid_Mesh* hexagonal_pyramid_mesh = new Hexagonal_Pyramid_Mesh();
	Texture* hexagonal_pyramid_texture = new Texture("Assets/moon.base.jpg");

	//Cheese_Wedge_Mesh* cheese_wedge_mesh = new Cheese_Wedge_Mesh();
	//Texture* cheese_wedge_texture = new Texture("Assets/texture.cheese.jpg");

	float a = 0.0f;
	float b = 0.0f;
	float c = 0.0f;
	float d = 0.0f;
	float sz = 0.0f;

	// Set up camera location and directions
	glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 camera_target = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);

	float yaw = -90.0f; // x
	float roll = 0.0f; // y
	float pitch = 0.0f; // z
	bool first_frame = true;

	// Set up aspect ratio params:
	float aspect_ratio = SCREEN_WIDTH / SCREEN_HEIGHT; // 1.5
	float default_world_size = 10.0f;
	float y_units = default_world_size;   // 2
	float x_units = aspect_ratio * y_units;    // 3
	float z_units = default_world_size;

	glm::mat4 projection;

	glm::mat4 ortho = glm::ortho(-x_units / 2, x_units / 2,
		-y_units / 2, y_units / 2,
		-1000.0f, 1000.0f);

	glm::mat4 perspective = glm::perspectiveFov(
		glm::radians(90.0f),
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0.1f,
		-1000.0f);

	projection = perspective;

	bool should_stop_rendering = false;
	bool camera_change = false;
	bool light_change = false;
	bool torch_change = false;
	while (should_stop_rendering == false)
	{
		if (escape_key_state == Key_State::PRESSED)
			escape_key_state = Key_State::HELD;
		if (space_key_state == Key_State::PRESSED)
			space_key_state = Key_State::HELD;
		if (w_key_state == Key_State::PRESSED)
			w_key_state = Key_State::HELD;
		if (a_key_state == Key_State::PRESSED)
			a_key_state = Key_State::HELD;
		if (s_key_state == Key_State::PRESSED)
			s_key_state = Key_State::HELD;
		if (d_key_state == Key_State::PRESSED)
			d_key_state = Key_State::HELD;
		if (h_key_state == Key_State::PRESSED)
			h_key_state = Key_State::HELD;
		if (t_key_state == Key_State::PRESSED)
			t_key_state = Key_State::HELD;

		glm::vec2 mouse_translation = glm::vec2(mouse_x_position - previous_mouse_x_position, mouse_y_position - previous_mouse_y_position);
		previous_mouse_x_position = mouse_x_position;
		previous_mouse_y_position = mouse_y_position;

		float sensitivity = 0.1f;
		mouse_translation.x *= sensitivity;
		mouse_translation.y *= sensitivity;

		yaw += mouse_translation.x;
		pitch -= mouse_translation.y;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 camera_forward = glm::normalize(camera_target - camera_position);
		bool hasnt_moved_cursor_yet = (previous_mouse_x_position == 0.0f && previous_mouse_y_position == 0.0f);
		if (inputs_captured > 2)
		{
			glm::vec3 direction;
			direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			direction.y = sin(glm::radians(pitch));
			direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			camera_forward = glm::normalize(direction);
		}

		glm::vec3 camera_right = glm::normalize(glm::cross(camera_forward, glm::vec3(0.f, 1.f, 0.f)));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		glm::vec3 camera_up = glm::normalize(glm::cross(camera_right, camera_forward));

		if (camera_change)
		{
			if (projection == ortho)
			{
				projection = perspective;
				camera_change = false;
			}
			else if (projection == perspective)
			{
				projection = ortho;
				camera_change = false;
			}
		}

		bool move_camera_forwards =
			w_key_state == Key_State::PRESSED ||
			w_key_state == Key_State::HELD;
		if (move_camera_forwards)
		{
			camera_position += camera_forward * 0.03f;
			camera_target += camera_forward * 0.03f;
		}
		bool move_camera_backwards =
			s_key_state == Key_State::PRESSED ||
			s_key_state == Key_State::HELD;
		if (move_camera_backwards)
		{
			camera_position -= camera_forward * 0.03f;
			camera_target -= camera_forward * 0.03f;
		}
		bool move_camera_right =
			d_key_state == Key_State::PRESSED ||
			d_key_state == Key_State::HELD;
		if (move_camera_right)
		{
			camera_position += camera_right * 0.03f;
			camera_target += camera_right * 0.03f;
		}
		bool move_camera_left =
			a_key_state == Key_State::PRESSED ||
			a_key_state == Key_State::HELD;
		if (move_camera_left)
		{
			camera_position -= camera_right * 0.03f;
			camera_target -= camera_right * 0.03f;
		}

		glm::mat4 camera;
		camera = glm::lookAt(camera_position, camera_position + camera_forward, camera_up);

		{
			// Cube
			glm::vec3 translation = glm::vec3(-1.0f, 0.0f, 0.0f);
			glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

			glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

			glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
			glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
			glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
			glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;

			glm::mat4 model = translation_m * rotation_m * scale_m;
			glm::mat4 final_transform = projection * camera * model;
			if (!torch_change)
				program->render(mesh, texture, &final_transform);
			else
				light_program->render(mesh, texture, &final_transform);
		}
		{
			// Robot
			glm::vec3 translation = glm::vec3(1.0f, 0.0f, 0.0f);
			glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 scale = glm::vec3(0.2f, 0.2f, 0.2f);

			glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

			glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
			glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
			glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
			glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;

			glm::mat4 model = translation_m * rotation_m * scale_m;
			glm::mat4 final_transform = projection * camera * model;
			if (!light_change)
				program->render(robot_mesh, robot_texture, &final_transform);
			else
				horror_program->render(robot_mesh, robot_texture, &final_transform);
		}
		{
			// Hexagonal Pyramid
			glm::vec3 translation = glm::vec3(-1.0f, 1.5f, 0.0f);
			glm::vec3 rotation = glm::vec3(0.0f, a, 0.0f);
			glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

			glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

			glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
			glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
			glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
			glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;

			glm::mat4 model = translation_m * rotation_m * scale_m;
			glm::mat4 final_transform = projection * camera * model;
			if (!light_change)
				program->render(hexagonal_pyramid_mesh, hexagonal_pyramid_texture, &final_transform);
			else
				horror_program->render(hexagonal_pyramid_mesh, hexagonal_pyramid_texture, &final_transform);
		}
		//{
		//	glm::vec3 translation = glm::vec3(-1.0f, 1.5f, 0.0f);
		//	glm::vec3 rotation = glm::vec3(0.0f, a, 0.0f);
		//	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
		//	glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), translation);
		//	glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);
		//	glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
		//	glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
		//	glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
		//	glm::mat4 rotation_m = rotation_x * rotation_y * rotation_z;
		//	glm::mat4 model = translation_m * rotation_m * scale_m;
		//	glm::mat4 final_transform = projection * camera * model;
		//	program->render(mesh, texture, &final_transform);
		//}

		// This renders the objects to the scene
		glfwSwapBuffers(window);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(0);
		glUseProgram(0);
		a += 0.05f;
		b += 0.05f;
		c += 0.0002f;
		d += 0.004f;

		glfwPollEvents();

		if (escape_key_state == Key_State::PRESSED)
			should_stop_rendering = true;
		if (space_key_state == Key_State::PRESSED)
			camera_change = true;
		if (h_key_state == Key_State::PRESSED)
			if (light_change == false)
				light_change = true;
			else if (light_change == true)
				light_change = false;
		if (t_key_state == Key_State::PRESSED)
			if (torch_change == false)
				torch_change = true;
			else if (torch_change == true)
				torch_change = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}
}