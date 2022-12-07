#pragma once
#include "glew.h"
#include "Vertex.h"
#include "glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"
#include "Texture.h"

namespace FrogEngine
{
	struct Quad
	{
		Vertex2f verteces[4];
		Quad(Vertex2f v0, Vertex2f v1, Vertex2f v2, Vertex2f v3);
		void SetTexture(std::string texture, unsigned int slot, Shader &shader, std::string samplerUniform);
	};
	Quad* CreateQuad(float x, float y, float xSize, float ySize);
	class Renderer
	{
	public:
		void Clear() const;
		void Draw(FrogEngine::VertexArray& vertexArray, FrogEngine::IndexBuffer& indexBuffer, Shader& shader) const;
	};
}