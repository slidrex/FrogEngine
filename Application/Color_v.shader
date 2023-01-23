#version 410

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 u_MVP;

out vec4 v_Color;

void main()
{
	v_Color = color;
	gl_Position = u_MVP * position;
}