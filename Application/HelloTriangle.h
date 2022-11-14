#include <Application.h>

class HelloTriangle : public FrogEngine::Application
{
public:
	void PreRender() override;
	void OnClose() override;
	void RenderUpdate() override;
};