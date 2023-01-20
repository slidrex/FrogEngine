#include "Renderer.h"
#include "Sandbox.h"
#include "FileParser.h"
#include <Camera.h>
#include <Events.h>
#include <Log.h>
#include <RenderStack.h>
#include <Shapes2D.h>

using namespace Murk;

Renderer* renderer;
RenderStack* stack;
Shape2D* square;

void Sandbox::OnStart()
{
	 renderer = new Renderer();
	 stack = new RenderStack(renderer);

	 square = CreateSquare(0.0f, 0.5f, 0.5f, 0.5f);

	 RenderStackElement *element = stack->PushRenderElement(ParseFile("Color_v.shader"), ParseFile("Color_f.shader"), square);
	 element->shader->Bind();
	 element->shader->SetMatrix4f("u_MVP", glm::mat4(1));
	 element->shader->SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
	 element->shader->Unbind();
	 renderer->SetClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
}
void Sandbox::OnUpdate()
{
	renderer->Clear();

	stack->DrawStack();
}
void Sandbox::OnWindowResize(int width, int height)
{
	glViewport(0, 0, width, height);
}
void Sandbox::OnClose()
{
	delete renderer;
	delete stack;
}