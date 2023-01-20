#include "ErrorCatcher.h"
#include "Log.h"

static void GLAPIENTRY Murk::OpenGLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		MURK_ERROR(message);
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		MURK_WARN(message);
		break;
	case GL_DEBUG_SEVERITY_LOW:
		MURK_LOG(message);
		break;
	}
}

void Murk::InitDebugger()
{
	glDebugMessageCallback(Murk::OpenGLErrorCallback, nullptr);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}