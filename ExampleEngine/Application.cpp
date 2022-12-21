#pragma once
#include "Log.h"
#include "ErrorCatcher.h"
#include "Application.h"
#include "Events.h"

void InitOpenGLContext(FrogEngine::Application* application);
void OpenGLRenderUpdate(FrogEngine::Application* application);

FrogEngine::Application* FrogEngine::Application::s_Instance = nullptr;

FrogEngine::Application::Application()
{
	deltaTime = 0;
	FrogEngine::Application::s_Instance = this;
	Window = nullptr;
}

void FrogEngine::EntryPoint::Run()
{
	InitOpenGLContext(m_application);

	m_application->PreRender();
	
	OpenGLRenderUpdate(m_application);
	
}
	static void window_size_callback(GLFWwindow* window, int width, int height)
	{
		FrogEngine::Application::GetApplication().OnWindowResize(width, height);
	}
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		FrogEngine::Application::GetApplication().OnMouseScrolling(yoffset);
	}
	void InitOpenGLContext(FrogEngine::Application* application)
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
	void OpenGLRenderUpdate(FrogEngine::Application* application)
	{
		while (glfwWindowShouldClose(application->Window) == false)
		{
			float beginTime = glfwGetTime();
			application->RenderUpdate(application->deltaTime);
			FrogEngine::InitDebugger();

			glfwSwapBuffers(application->Window);
			glfwPollEvents();
			float endTime = glfwGetTime();
			application->deltaTime = endTime - beginTime;
		}
		application->OnClose();
		glfwTerminate();
	}