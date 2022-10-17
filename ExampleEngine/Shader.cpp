#include <glew.h>
#include<iostream>
#include "Shader.h"
#include "FrogEngineFileParser.h"

using namespace FrogEngine;

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
void Shader::SetUniform4f(std::string name, float f1, float f2, float f3, float f4)
{
	unsigned int location = glGetUniformLocation(shader_program, name.c_str());
	glUniform4f(location, f1, f2, f3, f4);
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