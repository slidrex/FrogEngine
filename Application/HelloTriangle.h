#include <Application.h>

class HelloTriangle : public FrogEngine::Application
{
private:
	void SpeedCalculation();
	void HandleCollisions(glm::vec3& moveVector);
public:
	void PreRender() override;
	void OnClose() override;
	void RenderUpdate() override;
};