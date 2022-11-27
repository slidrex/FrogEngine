#include <glew.h>
#include "Shader.h"
#include "FrogEngineFileParser.h"
#include "Log.h"

using namespace FrogEngine;

int Shader::GetUniformLocation(const std::string& name) const
{
	if(uniformLocationCache.find(name) != uniformLocationCache.end())
	{
		return uniformLocationCache[name];
	}
	int location = glGetUniformLocation(m_Shader, name.c_str());
	uniformLocationCache[name] = location;
	return location;
}

Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
{
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
	
	const char* vertexSrc = vertexSource.c_str();
	const char* fragmentSrc = fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
	glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	GLint compileStatus;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);
	
	if (compileStatus == GL_FALSE) FROG_CRITICAL("Fragment shader error: {0}",  GetShaderInfoLog(fragmentShader));
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE) FROG_CRITICAL("Vertex shader error: {0}", GetShaderInfoLog(vertexShader));

	m_Shader = glCreateProgram();
	glAttachShader(m_Shader, fragmentShader);
	glAttachShader(m_Shader, vertexShader);
	glLinkProgram(m_Shader);
}
char* FrogEngine::Shader::GetShaderInfoLog(GLint shader)
{
	GLint length;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
	char *log = new char[length];
	glGetShaderInfoLog(shader, length, &length, log);
	return log;
}
void Shader::SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4)
{
	glUniform4f(GetUniformLocation(name), f1, f2, f3, f4);
}
void Shader::SetUniform1i(const std::string& name, int i)
{
	glUniform1i(GetUniformLocation(name), i);
}
void Shader::SetMatrix4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}
Shader::~Shader()
{
	Unbind();
	glDeleteProgram(m_Shader);
}
const void Shader::Bind()
{
	glUseProgram(m_Shader);
}
const void Shader::Unbind()
{
	glUseProgram(0);
}