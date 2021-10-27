#version 330 core

in vec2 interpolated_texture_coordinate;
uniform sampler2D image;
uniform sampler2D mask;

out vec4 fragment_color;

void main()
{
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    vec4 mask_textel = texture(mask, interpolated_texture_coordinate);
    if (mask_textel.r > 0.1)
    {
        fragment_color = image_textel;
    }
    else
    {
        fragment_color = vec4(0, 0, 0, 0);
    }
}