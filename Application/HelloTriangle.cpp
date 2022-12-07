#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>
#include <Camera.h>
#include <Transform.h>

using namespace FrogEngine;


unsigned int indeces[]
{
	0, 1, 2,
	2, 3, 0
};

Camera* camera;
VertexBuffer* vertexBuffer;
VertexArray* vertexArray;
IndexBuffer* indexBuffer;
Shader* shader;
Quad* quad;
Renderer* renderer;

float TriangleSpeed = 1.0f;
Transform *transform;

void HelloTriangle::PreRender()
{
	renderer = new Renderer();
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), -1.6f, 1.6f, -1.2f, 1.2f);


	vertexBuffer = new VertexBuffer(sizeof(Vertex2f) * 4);
	BufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);

	vertexArray = new VertexArray(*vertexBuffer, layout);
	vertexBuffer->Bind();

	transform = new Transform(glm::vec3(), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3());
	
	indexBuffer = new IndexBuffer(indeces, 6);

	shader = new Shader(ParseFile("Basicv.shader"), ParseFile("Basicf.shader"));
	shader->Bind();
	print("Z/V to zoom the camera");
	print("1/2 to scale along X axis");
	print("3/4 to scale along Y axis");
	print("W/A/S/D to change position of the quad");
	print("R/T to rotate the quad along Z axis");
	print("I: to get all the transform information");

	quad = CreateQuad(0.0f, 0.0f, 2.0f, 2.0f);
	quad->SetTexture("images/img.jpg", 0, *shader, "u_TexturePixels");

	shader->Unbind();
}
void HelloTriangle::RenderUpdate(float deltaTime)
{
	(*renderer).Clear();
	shader->Bind();
	vertexBuffer->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad->verteces), quad->verteces);

	if(Input::IsKeyPressed(GLFW_KEY_D))
	{
		transform->position.x += deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_A))
	{
		transform->position.x -= deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_W))
	{
		transform->position.y += deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_S))
	{
		transform->position.y -= deltaTime;
	}
	if(Input::IsKeyPressed(GLFW_KEY_R))
	{
		transform->rotation.z += deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_T))
	{
		transform->rotation.z -= deltaTime;
	}

	if(Input::IsKeyPressed(GLFW_KEY_1))
	{
		transform->scale.x += deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_2))
	{
		transform->scale.x -= deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_3))
	{
		transform->scale.y += deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_4))
	{
		transform->scale.y -= deltaTime;
	}
	if(Input::IsKeyPressed(GLFW_KEY_Z))
	{
		camera->Zoom(deltaTime);
	}
	if (Input::IsKeyPressed(GLFW_KEY_V))
	{
		camera->Zoom(-deltaTime);
	}
	if (Input::IsKeyPressed(GLFW_KEY_I))
	{
		print("");
		print("Position: ({0},{1})", transform->position.x, transform->position.y);
		print("Scale: ({0},{1})", transform->scale.x, transform->scale.y);
		print("Rotation: ({0})", transform->rotation.z);
	}

	(*shader).SetMatrix4f("u_MVP", camera->GetCameraProjection() * transform->GetModelProjection());
	(*renderer).Draw(*vertexArray, *indexBuffer, *shader);
}
void HelloTriangle::OnClose()
{
	delete vertexBuffer;
	delete vertexArray;
	delete shader;
	delete camera;
	delete renderer;
}
