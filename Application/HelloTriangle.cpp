#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>
#include <Camera.h>

using namespace FrogEngine;


unsigned int indeces[6]
{
	0, 1, 2,
	0, 3, 2
};

Camera* camera;
VertexBuffer* vertexBuffer;
VertexArray* vertexArray;
VertexBuffer* vertexBuffer1;
VertexArray* vertexArray1;
IndexBuffer* indexBuffer;
Shader* shader;
Renderer* renderer;


float TriangleSpeed = 0.01;

void HelloTriangle::PreRender()
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), -1.0f, 1.0f, -1.0f, 1.0f);
	renderer = new Renderer();


	Quad quad = CreateQuad(0.5f, 0.0f, 0.5f, 0.5f);
	Quad quad1 = CreateQuad(-0.5f, 0.0f, 0.5f, 0.5f);

	vertexBuffer = new VertexBuffer(quad.verteces, 4);
	vertexArray = new VertexArray(*vertexBuffer, 2);

	vertexBuffer1 = new VertexBuffer(quad1.verteces, 4);
	vertexArray1 = new VertexArray(*vertexBuffer, 2);

	indexBuffer = new IndexBuffer(indeces, sizeof(indeces));

	shader = new Shader(ParseFile("Basic.vert"), ParseFile("Basic.frag"));
	shader->Bind();
	(*shader).SetUniform4f("u_Color", 0.5f, 0.5f, 1, 1);
	shader->Unbind();
	FROG_LOG("Press arrows to move a camera");
	FROG_LOG("Press C/V to zoom a camera");
}
void HelloTriangle::RenderUpdate()
{
	(*renderer).Clear();
	shader->Bind();
	if(Input->IsKeyPressed(GLFW_KEY_UP))
	{
		camera->Move(glm::vec3(0.0f, TriangleSpeed, 0.0));
	}
	if (Input->IsKeyPressed(GLFW_KEY_LEFT))
	{
		camera->Move(glm::vec3(-TriangleSpeed, 0.0f, 0.0));
	}
	if (Input->IsKeyPressed(GLFW_KEY_DOWN))
	{
		camera->Move(glm::vec3(0.0, -TriangleSpeed, 0.0));
	}
	if (Input->IsKeyPressed(GLFW_KEY_RIGHT))
	{
		camera->Move(glm::vec3(TriangleSpeed, 0.0, 0.0));
	}
	if(Input->IsKeyPressed(GLFW_KEY_C))
	{
		camera->Zoom(0.01f);
	}
	if (Input->IsKeyPressed(GLFW_KEY_V))
	{
		camera->Zoom(-0.01f);
	}
	(*shader).SetMatrix4f("u_MVP", camera->GetCameraProjection());
	(*renderer).Draw(*vertexArray, *indexBuffer, *shader);

	(*renderer).Draw(*vertexArray1, *indexBuffer, *shader);
}
void HelloTriangle::OnClose()
{
	delete vertexBuffer;
	delete vertexArray;
	delete shader;
	delete camera;
	delete renderer;
}
