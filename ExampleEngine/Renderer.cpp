#include "Renderer.h"
#include "Texture.h"

using namespace FrogEngine;

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}
FrogEngine::Quad::Quad(Vertex2f v0, Vertex2f v1, Vertex2f v2, Vertex2f v3)
{
	verteces[0] = v0;
	verteces[1] = v1;
	verteces[2] = v2;
	verteces[3] = v3;
	
}
void FrogEngine::Quad::SetTexture(std::string texture, unsigned int slot, Shader &shader, std::string samplerUniform)
{
	Texture _texture = Texture(texture);
	_texture.Bind(slot);
	shader.SetUniform1i(samplerUniform, slot);
}
Quad* FrogEngine::CreateQuad(float x, float y, float xSize, float ySize)
{
	Vertex2f v0(x - xSize/2, y - ySize/2, 0.0f, 0.0f);
	Vertex2f v1(x - xSize/2, y + ySize/2, 0.0f, 1.0f);
	Vertex2f v2(x + xSize/2, y + ySize/2, 1.0f, 1.0f);
	Vertex2f v3(x + xSize/2, y - ySize/2, 1.0f, 0.0f);
	Quad* quad = new Quad(v0, v1, v2, v3);

	return quad;
}

void Renderer::Draw(FrogEngine::VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const
{
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}