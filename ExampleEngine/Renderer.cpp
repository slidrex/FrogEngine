#include "Renderer.h"

using namespace FrogEngine;

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}
Quad FrogEngine::CreateQuad(float x, float y, float xSize, float ySize)
{
	Vertex2f v0(x - xSize / 2, y - ySize / 2);
	Vertex2f v1(x - xSize / 2, y + ySize / 2);
	Vertex2f v2(x + xSize / 2, y + ySize / 2);
	Vertex2f v3(x + xSize / 2, y - ySize / 2);
	Quad quad(v0, v1, v2, v3);

	return quad;
}
void Renderer::Draw(FrogEngine::VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const
{
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}