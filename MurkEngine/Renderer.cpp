#include "Renderer.h"
#include "Texture.h"

using namespace Murk;

void Renderer::Clear() const
{
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Murk::Renderer::SetClearColor(glm::vec4 color)
{
	clearColor = color;
}
void Renderer::Draw(RenderMode renderMode, Murk::VertexArray& vertexArray, Shader& shader, IndexBuffer& indexBuffer) const
{
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();
	glDrawElements(renderMode, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}