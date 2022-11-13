#pragma once
#include "Log.h"
#include "ErrorCatcher.h"
#include "Application.h"

void InitOpenGLContext(FrogEngine::Application* application);
void OpenGLRenderUpdate(FrogEngine::Application* application);


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
		application->m_Window = glfwCreateWindow(windowWeight, windowHeight, "FrogEngine", NULL, NULL);


		glfwMakeContextCurrent(application->m_Window);

		if (glewInit() != GLEW_OK) FROG_CRITICAL("GLEW is not setup.");
		return;
	}

	void OpenGLRenderUpdate(FrogEngine::Application* application)
	{
		while (glfwWindowShouldClose(application->m_Window) == false)
		{
			application->RenderUpdate();
			FrogEngine::InitDebugger();
			

			glfwSwapBuffers(application->m_Window);
			glfwPollEvents();
		}
		application->OnClose();
		glfwTerminate();
	}