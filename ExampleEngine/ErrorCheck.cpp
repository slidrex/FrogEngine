#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "ErrorChecker.h"

class ErrorDebugger
{
public:
	static void GLClearError()
	{

	}
	static void GETERROR()
	{
		GLenum error = glGetError();
	
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL ERROR!";
		}
	}

};
