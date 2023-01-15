#include "ErrorCatcher.h"
#include "EntryPoint.h"
#include "Log.h"


FrogEngine::EntryPoint::EntryPoint(Application* application)
{
	m_application = application;
}

void FrogEngine::EntryPoint::Run()
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
	FrogEngine::Application::GetApplication().OnWindowResize(width, height);
}
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	FrogEngine::Application::GetApplication().OnMouseScrolling(yoffset);
}
void FrogEngine::EntryPoint::RenderInit(FrogEngine::Application* application)
{
	if (!glfwInit())
	{
		FROG_CRITICAL("GLEW is not setup.");
		return;
	}
	int windowWeight = 500 * 2, windowHeight = 500 * 2;
	application->Window = glfwCreateWindow(windowWeight, windowHeight, "FrogEngine", NULL, NULL);



	glfwMakeContextCurrent(application->Window);
	if (glewInit() != GLEW_OK) FROG_CRITICAL("GLEW is not setup.");
	glfwSetWindowSizeCallback(application->Window, window_size_callback);
	glfwSetScrollCallback(application->Window, scroll_callback);
	FrogEngine::InitDebugger();
	return;
}
void FrogEngine::EntryPoint::RenderUpdate(FrogEngine::Application* application, std::vector<FrogEngine::Layer*> layers)
{
	while (glfwWindowShouldClose(application->Window) == false)
	{
		float beginTime = glfwGetTime();

		for (FrogEngine::Layer* layer : layers)
		{
			layer->OnUpdate();
		}

		FrogEngine::InitDebugger();

		glfwSwapBuffers(application->Window);
		glfwPollEvents();
		float endTime = glfwGetTime();
		application->deltaTime = endTime - beginTime;
	}
	for (FrogEngine::Layer* layer : layers)
	{
		layer->OnClose();
	}
	glfwTerminate();
}