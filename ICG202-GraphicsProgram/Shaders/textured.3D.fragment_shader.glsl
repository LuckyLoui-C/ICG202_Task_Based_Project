#version 330 core

in vec2 interpolated_texture_coordinate;
in vec3 pixel_coordinate;
uniform sampler2D image;

uniform vec3 lighting_position;
uniform vec3 lighting_color;
uniform float lighting_brightness;

out vec4 fragment_color;

void main()
{
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    image_textel *= 0.4;

    vec3 pixel_to_light = lighting_position - pixel_coordinate;
    float magnitude = length(pixel_to_light);

    vec3 lighting_color_final = lighting_color.xyz * 0.6 * (1.0 - magnitude);

    //vec3 lighting_color_final = lighting_color.xyz * lighting_brightness;
    image_textel += vec4(lighting_color_final.xyz, 1.0);
    fragment_color    = vec4(image_textel.xyz, 1);
}