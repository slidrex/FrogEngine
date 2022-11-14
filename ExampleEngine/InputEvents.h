#pragma once
#include <glfw3.h>

namespace FrogEngine
{
	class InputSystem
	{
	public:
		InputSystem(GLFWwindow* window);
		bool IsKeyPressed(int key);
	private:
		GLFWwindow* m_Window;
	};
}
