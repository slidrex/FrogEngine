#pragma once
#include "Layer.h"
#include "glfw3.h"

namespace FrogEngine
{
	class Application : protected Layer
	{
	public:
		Application();
		static Application& GetApplication()  { return *s_Instance; }
		GLFWwindow* Window;
		virtual void OnMouseScrolling(double offset) { }
		virtual void OnWindowResize(int width, int height) { }
		float deltaTime;
		LayerStack* layerStack;
	private:
		static Application* s_Instance;
	};
}
