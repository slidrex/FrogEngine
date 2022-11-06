#pragma once

#include "glew.h"

namespace FrogEngine
{
	static void GLAPIENTRY OpenGLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

	void InitDebugger();
}