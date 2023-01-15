#version 410

layout(location = 0) out vec4 color;

in vec2 v_TextureCoords;
uniform float uv_x;
uniform sampler2D u_TexturePixels;

void main()
{
	color = texture(u_TexturePixels, vec2(v_TextureCoords.x + uv_x, v_TextureCoords.y));
}