#include <FrogEngine.h>
#include "HelloTriangle.h"
#include "ErrorCatcher.h"
#include <FrogEngineFileParser.h>

int main()
{
	FrogEngine::EntryPoint* app = new FrogEngine::EntryPoint(new HelloTriangle());
	(*app).Run();
	delete app;
}
