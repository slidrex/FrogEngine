#include "ErrorCatcher.h"
#include "EntryPoint.h"
#include "Log.h"


Murk::EntryPoint::EntryPoint(Application* application)
{
	m_application = application;
}

void Murk::EntryPoint::Run()
{
	RenderInit(m_application);

	for (Layer* layer : m_application->layerStack->layers)
	{
		layer->OnStart();
	}

	RenderUpdate(m_application, m_application->layerStack->layers);

}
static void window_size_callback(GLFWwindow* window, int width, int height)
{
	Murk::Application::GetApplication().OnWindowResize(width, height);
}
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Murk::Application::GetApplication().OnMouseScrolling(yoffset);
}
void Murk::EntryPoint::RenderInit(Murk::Application* application)
{
	if (!glfwInit())
	{
		MURK_CRITICAL("GLEW is not setup.");
		return;
	}
	int windowWeight = 500 * 2, windowHeight = 500 * 2;
	application->Window = glfwCreateWindow(windowWeight, windowHeight, "Murk", glfwGetPrimaryMonitor(), NULL);



	glfwMakeContextCurrent(application->Window);
	if (glewInit() != GLEW_OK) MURK_CRITICAL("GLEW is not setup.");
	glfwSetWindowSizeCallback(application->Window, window_size_callback);
	glfwSetScrollCallback(application->Window, scroll_callback);
	Murk::InitDebugger();
	return;
}
void Murk::EntryPoint::RenderUpdate(Murk::Application* application, std::vector<Murk::Layer*> layers)
{
	while (glfwWindowShouldClose(application->Window) == false)
	{
		float beginTime = glfwGetTime();

		for (Murk::Layer* layer : layers)
		{
			layer->OnUpdate();
		}

		Murk::InitDebugger();

		glfwSwapBuffers(application->Window);
		glfwPollEvents();
		float endTime = glfwGetTime();
		application->deltaTime = endTime - beginTime;
	}
	for (Murk::Layer* layer : layers)
	{
		layer->OnClose();
	}
	glfwTerminate();
}