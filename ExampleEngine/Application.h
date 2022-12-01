#pragma once
#include "glfw3.h"

namespace FrogEngine
{
	class Application
	{
	public:
		Application();
		static Application& GetApplication()  { return *s_Instance; }
		GLFWwindow* Window;
		
		/// <summary>
		/// Runs before render loop
		/// </summary>
		virtual void PreRender() { }
		/// <summary>
		/// Runs render loop
		/// </summary>
		virtual void RenderUpdate(float deltaTime) { }
		/// <summary>
		/// Calls before application quit
		/// </summary>
		virtual void OnClose() { }
		float deltaTime;
	private:
		static Application* s_Instance;
	};
	class EntryPoint
	{
	public:
		Application* m_application;
		EntryPoint(Application* application) { m_application = application; }
		void Run();
	};
}
