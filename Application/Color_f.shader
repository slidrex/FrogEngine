#version 410

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
in vec4 v_Color;

void main()
{
	color = v_Color;
}