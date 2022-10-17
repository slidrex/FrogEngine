#version 330 core

#vertex

layout(location = 0) in vec4 pos;
int main()
{
	gl_Position = pos;
	return 0;
}

#fragment

layout(location = 0) out vec4 color;
int main()
{
	gl_Color = vec4(1.0, 1.0, 0.5, 1.0);
	return 0;
}
