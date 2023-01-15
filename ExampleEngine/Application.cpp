#pragma once
#include "Application.h"
#include "EntryPoint.h"


FrogEngine::Application* FrogEngine::Application::s_Instance = nullptr;

FrogEngine::Application::Application()
{
	deltaTime = 0;
	FrogEngine::Application::layerStack = new LayerStack();
	FrogEngine::Application::s_Instance = this;
	Window = nullptr;
}