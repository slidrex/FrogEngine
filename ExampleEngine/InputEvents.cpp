#include "InputEvents.h"
#include "Application.h"

bool FrogEngine::InputSystem::IsKeyPressed(int key) { return glfwGetKey(FrogEngine::InputSystem::m_Window, key); }
FrogEngine::InputSystem::InputSystem(GLFWwindow* window) { m_Window = window; }