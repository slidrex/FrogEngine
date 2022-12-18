#pragma once
#include <Application.h>

class HelloTriangle : public FrogEngine::Application
{
public:
	void PreRender() override;
	void OnClose() override;
	void OnMouseScrolling(double offset) override;
	void OnWindowResize(int width, int height) override;
	void RenderUpdate(float deltaTime) override;
};