#include <glew.h>
#include "Shader.h"
#include "FrogEngineFileParser.h"

using namespace FrogEngine;

int Shader::GetUniformLocation(const std::string& name) const
{
	if(uniformLocationCache.find(name) != uniformLocationCache.end())
	{
		return uniformLocationCache[name];
	}
	int location = glGetUniformLocation(shader_program, name.c_str());
	uniformLocationCache[name] = location;
	return location;
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	unsigned int shader;
	unsigned int fragmentShader, vertexShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexSource = FrogEngine::ParseFile(vertexPath);
	std::string fragmentSource = FrogEngine::ParseFile(fragmentPath);
	const char* vertexSrc = vertexSource.c_str();
	const char* fragmentSrc = fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
	glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	fragment_shader = fragmentShader;
	vertex_shader = vertexShader;
	shader = glCreateProgram();
	glAttachShader(shader, fragmentShader);
	glAttachShader(shader, vertexShader);
	glLinkProgram(shader);
	shader_program = shader;
	
}
void Shader::SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4)
{
	glUniform4f(GetUniformLocation(name), f1, f2, f3, f4);
}
void Shader::SetMatrix4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}
Shader::~Shader()
{
	Unbind();
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	glDeleteProgram(shader_program);
}
const void Shader::Bind()
{
	glUseProgram(shader_program);
}
const void Shader::Unbind()
{
	glUseProgram(0);
}