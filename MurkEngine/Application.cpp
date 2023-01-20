#pragma once
#include "Application.h"
#include "EntryPoint.h"


Murk::Application* Murk::Application::s_Instance = nullptr;

Murk::Application::Application()
{
	deltaTime = 0;
	Murk::Application::layerStack = new LayerStack();
	Murk::Application::s_Instance = this;
	Window = nullptr;
}