#include "Renderer.h"
#include "Texture.h"

using namespace Murk;

Renderer Renderer::s_Instance;

Renderer::Renderer()
{
	s_Instance.clearColor = glm::vec4(0);
}

void Renderer::Clear()
{
	glClearColor(Renderer::s_Instance.clearColor.x, Renderer::s_Instance.clearColor.y, Renderer::s_Instance.clearColor.z, Renderer::s_Instance.clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Murk::Renderer::SetClearColor(glm::vec4 color)
{
	Renderer::s_Instance.clearColor = color;
}
void Renderer::Draw(RenderMode renderMode, Murk::VertexArray& vertexArray, Shader& shader, IndexBuffer& indexBuffer)
{
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();
	glDrawElements(renderMode, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}