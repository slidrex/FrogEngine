#pragma once
#include<iostream>

namespace FrogEngine
{
	class Shader
	{
	private:
		unsigned int shader_program;
		unsigned int vertex_shader;
		unsigned int fragment_shader;
	public:

		Shader(const std::string& vertexPath, const std::string& fragmentPath);
		~Shader();
		const void Bind();
		const void Unbind();
		void SetUniform4f(std::string name, float f1, float f2, float f3, float f4);
	};
	enum ShaderType
	{
		Vertex = 0,
		Fragment = 1
	};
	struct ShaderSource
	{
		std::string VertexSource;
		std::string FragmentSource;
		ShaderSource(std::string vertex, std::string fragment)
		{
			VertexSource = vertex;
			FragmentSource = fragment;
		}
	};
}