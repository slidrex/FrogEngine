#include "glfw3.h"
#include "Events.h"
#include "Application.h"

bool FrogEngine::Events::IsKeyPressed(int key)
{
	GLFWwindow* window = FrogEngine::Application::GetApplication().Window;
	return glfwGetKey(window, key);
}
bool FrogEngine::Events::IsMousePressed(int button)
{
	GLFWwindow* window = FrogEngine::Application::GetApplication().Window;
	return glfwGetMouseButton(window, button);
}
float FrogEngine::Events::GetAspectRatio()
{
	int x;
	int y;
	GLFWwindow* window = FrogEngine::Application::GetApplication().Window;
	glfwGetWindowSize(window, &x, &y);
	return x / (float)y;
}
glm::vec2 FrogEngine::Events::GetMousePos()
{
	double x;
	double y;
	GLFWwindow* window = FrogEngine::Application::GetApplication().Window;
	
	glfwGetCursorPos(window, &x, &y);
	return glm::vec2(x, y);
}