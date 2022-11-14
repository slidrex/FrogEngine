#pragma once
#include "glfw3.h"
#include "InputEvents.h"

namespace FrogEngine
{
	class Application
	{
	public:
		InputSystem* Input;
		GLFWwindow* m_Window;
		/// <summary>
		/// Runs before render loop
		/// </summary>
		virtual void PreRender() { }
		/// <summary>
		/// Runs render loop
		/// </summary>
		virtual void RenderUpdate() { }
		/// <summary>
		/// Calls before application quit
		/// </summary>
		virtual void OnClose() { }
	};
	class EntryPoint
	{
	public:
		Application* m_application;
		EntryPoint(Application* application) { m_application = application; }
		void Run();
	};
}
