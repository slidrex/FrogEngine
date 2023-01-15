#pragma once
#include "Application.h"

namespace FrogEngine
{
	class EntryPoint
	{
	private:
		void RenderInit(FrogEngine::Application*);
		void RenderUpdate(FrogEngine::Application*, std::vector<FrogEngine::Layer*>);
	public:
		Application* m_application;
		EntryPoint(Application* application);
		void Run();
	};
}