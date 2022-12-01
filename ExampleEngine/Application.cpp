#pragma once
#include "Log.h"
#include "ErrorCatcher.h"
#include "Application.h"

void InitOpenGLContext(FrogEngine::Application* application);
void OpenGLRenderUpdate(FrogEngine::Application* application);

FrogEngine::Application* FrogEngine::Application::s_Instance = nullptr;

FrogEngine::Application::Application()
{
	FrogEngine::Application::s_Instance = this;
	Window = nullptr;
}

void FrogEngine::EntryPoint::Run()
{
	InitOpenGLContext(m_application);

	m_application->PreRender();
	
	OpenGLRenderUpdate(m_application);
	
}

	void InitOpenGLContext(FrogEngine::Application* application)
	{
		if (!glfwInit())
		{
			FROG_CRITICAL("GLEW is not setup.");
			return;
		}
		int windowWeight = 640, windowHeight = 480;
		application->Window = glfwCreateWindow(windowWeight, windowHeight, "FrogEngine", NULL, NULL);


		glfwMakeContextCurrent(application->Window);
		if (glewInit() != GLEW_OK) FROG_CRITICAL("GLEW is not setup.");
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