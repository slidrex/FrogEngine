#include "glfw3.h"
#include "Events.h"
#include "Application.h"

bool FrogEngine::Input::IsKeyPressed(int key)
{
	GLFWwindow* window = FrogEngine::Application::GetApplication().Window;
	return glfwGetKey(window, key);
}