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
	enum RenderMode
	{
		Triangles = GL_TRIANGLES,
		Pixels = GL_POINTS,
		Lines = GL_LINES
	};
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
		void SetClearColor(glm::vec4 color);
		void Clear() const;
		void SetPixelSize(float size) { glPointSize(size); };
		void SetLineSize(float size) { glLineWidth(size); };
		void Draw(RenderMode renderMode, FrogEngine::VertexArray& vertexArray, Shader& shader, FrogEngine::IndexBuffer& indexBuffer) const;
	private:
		glm::vec4 clearColor;
	};
}