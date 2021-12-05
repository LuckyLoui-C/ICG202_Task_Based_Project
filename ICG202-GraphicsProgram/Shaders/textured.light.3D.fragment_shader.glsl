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
    
    // Vector -> from pixel to the light source
    vec3 pixel_to_light = lighting_position - pixel_coordinate;
    vec3 pixel_to_light_direction = normalize(pixel_to_light);
    float light_brightness = (dot(pixel_to_light_direction, pixel_normal) + 1) / 2.0;
    light_brightness = pow(light_brightness, 5);
    light_brightness *= 5.5;
    light_brightness += 0.2;

    fragment_color = vec4(image_textel.rgb * light_brightness * vec3(1.0, 1.0, 1.0), 1);
}