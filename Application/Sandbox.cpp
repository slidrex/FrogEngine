#include "Renderer.h"
#include "Sandbox.h"
#include "FileParser.h"
#include <Camera.h>
#include <Events.h>
#include <Log.h>
#include <RenderStack.h>
#include <Shapes3D.h>

using namespace Murk;

RenderStack* stack;
Murk::Shape3D* cube;
Camera* camera;

void Sandbox::OnStart()
{
	 stack = new RenderStack();
	 camera = new Camera(glm::vec3(0), glm::vec3(0), -1.0f, 1.0f, -1.0f, 1.0f);
	 cube = CreateCube(0.0f, 0.0f);
	 
	 RenderStackElement *element = stack->PushRenderElement(ParseFile("Color_v.shader"), ParseFile("Color_f.shader"), cube);
	 element->shader->Bind();
	 element->shader->SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
	 element->shader->Unbind();
	 glEnable(GL_DEPTH_TEST);
	 Renderer::SetClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
}
void Sandbox::OnUpdate()
{
	Renderer::Clear();
	stack->m_RenderElements[0]->shader->Bind();
	

	stack->m_RenderElements[0]->shader->SetMatrix4f("u_MVP", camera->GetCameraProjection());
	
	camera->Rotate(glm::vec3(deltaTime, 0.0f, 0.0f));
	camera->Rotate(glm::vec3(0.0f, deltaTime, 0.0f));
	camera->Rotate(glm::vec3(0.0f, 0.0f, deltaTime));
	if (Events::IsKeyPressed(GLFW_KEY_A))
	{
		camera->Move(glm::vec3(-deltaTime, 0.0f, 0.0f));
	}
	if (Events::IsKeyPressed(GLFW_KEY_D))
	{
		camera->Move(glm::vec3(deltaTime, 0.0f, 0.0f));
	}
	stack->DrawStack();
}
void Sandbox::OnWindowResize(int width, int height)
{
	glViewport(0, 0, width, height);
	float aspectRatio = (float)width / height;
	camera->m_Projection.x = camera->m_SourceProejction.x * aspectRatio;
	camera->m_Projection.y = camera->m_SourceProejction.y * aspectRatio;
}
void Sandbox::OnClose()
{
	delete stack;
	delete cube;
}