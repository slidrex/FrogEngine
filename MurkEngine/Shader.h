#pragma once

#include <iostream>
#include <unordered_map>
#include "glm/glm.hpp"

namespace Murk
{

	class Shader
	{
	public:

		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();
		const void Bind();
		const void Unbind();
		void SetUniform1f(const std::string& name, float f);
		void SetMatrix4f(const std::string& name, const glm::mat4& matrix);
		void SetUniform1i(const std::string& name, const int i);
		void SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
	private:
		mutable std::unordered_map<std::string, int> uniformLocationCache;
		unsigned int m_Shader;
		char* GetShaderInfoLog(GLint shader);
		int GetUniformLocation(const std::string &name) const;
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