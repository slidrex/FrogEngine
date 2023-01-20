#pragma once
#include <vector>

namespace Murk
{
	class Layer
	{
	public:
		Layer* GetLayer() { return this; }
		virtual void OnStart() {}
		virtual void OnUpdate() {}
		virtual void OnClose() {}
	};
	class LayerStack
	{
	public:
		std::vector<Layer*> layers;
		void PushLayer(Murk::Layer* layer) { layers.push_back(layer); }
	};
}