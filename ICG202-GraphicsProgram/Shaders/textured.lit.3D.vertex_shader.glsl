#version 330 core

in vec3 vertex_position;
in vec2 vertex_texture_coordinate;
in vec3 vertex_normal;

out vec2 interpolated_texture_coordinate;
out vec3 pixel_coordinate;
out vec3 pixel_normal;

uniform mat4 transformation;

void main()
{
    vec4 vertex_position_transformed = transformation * vec4(vertex_position.xyz, 1.0);

    gl_Position                     = vertex_position_transformed;
    interpolated_texture_coordinate = vertex_texture_coordinate;
    pixel_coordinate = vertex_position_transformed.xyz;
    //pixel_normal = (transformation * vec4(vertex_normal.xyz, 1.0)).xyz;
    pixel_normal = vertex_normal.xyz;
}