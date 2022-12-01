#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>
#include <Camera.h>
#include <Texture.h>

using namespace FrogEngine;

float positions[]
{
	-0.5f, -0.5f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, 1.0f, 0.0f
};


unsigned int indeces[]
{
	0, 1, 2,
	0, 3, 2
};

Camera* camera;
VertexBuffer* vertexBuffer;
VertexArray* vertexArray;
IndexBuffer* indexBuffer;
Shader* shader;
Renderer* renderer;

int flip = 1;
float TriangleSpeed = 1.0f;
float xPos, yPos;

void HelloTriangle::PreRender()
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), -1.6, 1.6, -1.2, 1.2);
	renderer = new Renderer();


	Quad quad = CreateQuad(0.5f, 0.0f, 0.5f, 0.5f);
	

	BufferLayout layout;
	vertexBuffer = new VertexBuffer(positions, 4 * sizeof(float) * 4);
	layout.Push<float>(2); //verteces position
	layout.Push<float>(2); //texture coordinates
	vertexArray = new VertexArray(*vertexBuffer, layout);
	xPos = 0;
	yPos = 0;
	
	indexBuffer = new IndexBuffer(indeces, sizeof(indeces));
	shader = new Shader(ParseFile("Basicv.shader"), ParseFile("Basicf.shader"));
	shader->Bind();
	
	Texture texture = Texture("images/ghost.png");
	texture.Bind(0);

	shader->SetUniform1i("u_TexturePixels", 0);
	shader->Unbind();


	FROG_LOG("Press arrows to move a camera");
	FROG_LOG("Press C/V to zoom a camera");
}
void HelloTriangle::RenderUpdate(float deltaTime)
{
	(*renderer).Clear();
	shader->Bind();

	if(Input::IsKeyPressed(GLFW_KEY_UP))
	{
		yPos += TriangleSpeed * deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_LEFT))
	{
		xPos -= TriangleSpeed * deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_DOWN))
	{
		yPos -= TriangleSpeed * deltaTime;
	}
	if (Input::IsKeyPressed(GLFW_KEY_RIGHT))
	{
		xPos += TriangleSpeed * deltaTime;
	}
	if(Input::IsKeyPressed(GLFW_KEY_C))
	{
		camera->Zoom(TriangleSpeed * deltaTime);
	}
	if (Input::IsKeyPressed(GLFW_KEY_V))
	{
		camera->Zoom(-TriangleSpeed * deltaTime);
	}
	

	glm::mat4 ghostPos = glm::translate(glm::mat4(1), glm::vec3(xPos, yPos, 0));
	(*shader).SetMatrix4f("u_MVP", camera->GetCameraProjection() * ghostPos);
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
