#pragma once
#include "Application.h"

class PixelEditor : public FrogEngine::Application
{
private:
	void OnStart() override;
	void OnUpdate() override;
	void OnWindowResize(int x, int y) override;
	void OnClose() override;
public:
	PixelEditor()
	{
		layerStack->PushLayer(GetLayer());
	}
};