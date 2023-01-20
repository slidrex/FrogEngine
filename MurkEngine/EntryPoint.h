#pragma once
#include "Application.h"

namespace Murk
{
	class EntryPoint
	{
	private:
		void RenderInit(Murk::Application*);
		void RenderUpdate(Murk::Application*, std::vector<Murk::Layer*>);
	public:
		Application* m_application;
		EntryPoint(Application* application);
		void Run();
	};
}