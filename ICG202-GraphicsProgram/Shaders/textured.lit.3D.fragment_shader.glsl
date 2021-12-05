#version 330 core

in vec2 interpolated_texture_coordinate; // slice of an array.
in vec3 pixel_coordinate;
in vec3 pixel_normal;
uniform sampler2D image; // shared.

uniform vec3 lighting_position;
uniform vec3 lighting_color;
uniform float lighting_brightness;

out vec4 fragment_color;

void main()
{
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    vec3 image_textel_lit = image_textel.rgb * lighting_color * lighting_brightness;
    fragment_color = vec4(image_textel_lit.xyz, 1);
}