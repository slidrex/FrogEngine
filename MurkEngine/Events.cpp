#include "glfw3.h"
#include "Events.h"
#include "Application.h"

bool Murk::Events::IsKeyPressed(int key)
{
	GLFWwindow* window = Murk::Application::GetApplication().Window;
	return glfwGetKey(window, key);
}
bool Murk::Events::IsMousePressed(int button)
{
	GLFWwindow* window = Murk::Application::GetApplication().Window;
	return glfwGetMouseButton(window, button);
}
float Murk::Events::GetAspectRatio()
{
	int x;
	int y;
	GLFWwindow* window = Murk::Application::GetApplication().Window;
	glfwGetWindowSize(window, &x, &y);
	return x / (float)y;
}
glm::vec2 Murk::Events::GetMousePos()
{
	double x;
	double y;
	GLFWwindow* window = Murk::Application::GetApplication().Window;
	
	glfwGetCursorPos(window, &x, &y);
	return glm::vec2(x, y);
}