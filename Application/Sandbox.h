#pragma once
#include "Application.h"

class Sandbox : public Murk::Application
{
private:
	void OnStart() override;
	void OnUpdate() override;
	void OnWindowResize(int x, int y) override;
	void OnClose() override;
public:
	Sandbox()
	{
		layerStack->PushLayer(GetLayer());
	}
};