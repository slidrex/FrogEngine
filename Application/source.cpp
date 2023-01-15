#include <FrogEngine.h>
#include "PixelEditor.h"
#include "ErrorCatcher.h"
#include <FrogEngineFileParser.h>
#include "EntryPoint.h"

int main()
{
	FrogEngine::EntryPoint* app = new FrogEngine::EntryPoint(new PixelEditor());
	(*app).Run();
	delete app;
}
