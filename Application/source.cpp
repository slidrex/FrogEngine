#include <FrogEngine.h>
#include "HelloTriangle.h"

int main()
{
	FrogEngine::EntryPoint* app = new FrogEngine::EntryPoint(new HelloTriangle());
	(*app).Run();
	delete app;

	return 0;
}
