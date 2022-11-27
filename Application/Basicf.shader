#version 410

layout(location = 0) out vec4 color;

in vec2 v_TextureCoords;
uniform sampler2D u_TexturePixels;

void main()
{
	color = texture(u_TexturePixels, v_TextureCoords);
}