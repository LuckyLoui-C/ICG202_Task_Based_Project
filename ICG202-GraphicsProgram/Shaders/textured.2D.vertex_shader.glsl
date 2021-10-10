#version 330 core

in vec2 vertex_position;
in vec2 vertex_texture_coordinate;

out vec2 interpolated_texture_coordinate;

void main()
{
    vec4 transformed_position = vec4(vertex_position.xy, 1.0, 1.0);
    gl_Position = vec4(transformed_position.xy, 0.0, 1.0);
    interpolated_texture_coordinate = vertex_texture_coordinate;
}