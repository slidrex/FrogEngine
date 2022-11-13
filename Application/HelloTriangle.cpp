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

void HelloTriangle::PreRender()
{
	vertexBuffer = new VertexBuffer(positions, sizeof(positions));
	vertexArray = new VertexArray(*vertexBuffer, 2);
	indexBuffer = new IndexBuffer(indeces, sizeof(indeces));

	renderer = new Renderer();
	shader = new Shader(ParseFile("Basic.vert"), ParseFile("Basic.frag"));

	//(*shader).Bind();

	//(*shader).SetMatrix4f("u_MVP", projection);
	//(*shader).SetUniform4f("u_Color", 0.5f, 0.5f, 1, 1);
}
void HelloTriangle::RenderUpdate()
{
	(*renderer).Draw(RenderMode::Triangles, *vertexArray, *indexBuffer, *shader);
}
void HelloTriangle::OnClose()
{
	delete vertexBuffer;
	delete vertexArray;
	delete shader;
	delete renderer;
}