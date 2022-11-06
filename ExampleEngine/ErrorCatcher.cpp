#include "ErrorCatcher.h"
#include "Log.h"

static void GLAPIENTRY FrogEngine::OpenGLErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		FROG_ERROR(message);
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		FROG_WARN(message);
		break;
	case GL_DEBUG_SEVERITY_LOW:
		FROG_LOG(message);
		break;
	}
}

void FrogEngine::InitDebugger()
{
	glDebugMessageCallback(FrogEngine::OpenGLErrorCallback, nullptr);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}