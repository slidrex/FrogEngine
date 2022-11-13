#include "Renderer.h"

using namespace FrogEngine;

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::Draw(RenderMode renderMode, FrogEngine::VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const
{
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();
	glDrawElements(renderMode, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}