#include <MurkEngine.h>
#include "Sandbox.h"
#include "ErrorCatcher.h"
#include <FileParser.h>
#include "EntryPoint.h"

int main()
{
	Murk::EntryPoint* app = new Murk::EntryPoint(new Sandbox());
	(*app).Run();
	delete app;
}
