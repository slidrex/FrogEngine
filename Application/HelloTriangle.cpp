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
	shader = new Shader(ParseFile("ExampleEngine/Basic.vert"), ParseFile("ExampleEngine/Basic.frag"));
	(*shader).Bind();
	renderer = new Renderer();
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