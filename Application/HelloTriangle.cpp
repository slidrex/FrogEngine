#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>

using namespace FrogEngine;

float positions[6]
{
	-0.5f, 0.0f,
	0.0, 0.5f,
	0.5f, 0.0f
};
unsigned int indeces[3]
{
	0, 1, 2
};

VertexBuffer* vertexBuffer;
VertexArray* vertexArray;
IndexBuffer* indexBuffer;
Shader* shader;
Renderer* renderer;

glm::vec3* position;

float TriangleSpeed = 0.01;

void HelloTriangle::PreRender()
{
	vertexBuffer = new VertexBuffer(positions, sizeof(positions));
	vertexArray = new VertexArray(*vertexBuffer, 2);
	indexBuffer = new IndexBuffer(indeces, sizeof(indeces));

	renderer = new Renderer();
	position = new glm::vec3(0, 0, 0);
	shader = new Shader(ParseFile("Basic.vert"), ParseFile("Basic.frag"));
}
void HelloTriangle::RenderUpdate()
{
	(*renderer).Clear();
	if(Input->IsKeyPressed(GLFW_KEY_W) && position->y < 0.5)
	{
		position->y += TriangleSpeed;
	}
	if (Input->IsKeyPressed(GLFW_KEY_A) && position->x > -0.5)
	{
		position->x -= TriangleSpeed;
	}
	if (Input->IsKeyPressed(GLFW_KEY_S) && position->y > -1)
	{
		position->y -= TriangleSpeed;
	}
	if (Input->IsKeyPressed(GLFW_KEY_D) && position->x < 0.5)
	{
		position->x += TriangleSpeed;
	}
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0, 0));
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
	


	glm::mat4 modelMatrix = glm::translate(glm::mat4(1), *position);
	
	(*shader).SetMatrix4f("u_MVP", view * projection * modelMatrix);
	(*shader).SetUniform4f("u_Color", 0.5f, 0.5f, 1, 1);
	(*renderer).Draw(RenderMode::Triangles, *vertexArray, *indexBuffer, *shader);
}
void HelloTriangle::OnClose()
{
	delete vertexBuffer;
	delete vertexArray;
	delete shader;
	delete renderer;
}
