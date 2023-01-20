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

namespace Murk
{
	enum RenderMode
	{
		Triangles = GL_TRIANGLES,
		Pixels = GL_POINTS,
		Lines = GL_LINES
	};
	class Renderer
	{
	public:
		void SetClearColor(glm::vec4 color);
		void Clear() const;
		void SetPixelSize(float size) { glPointSize(size); };
		void SetLineSize(float size) { glLineWidth(size); };
		void Draw(RenderMode renderMode, Murk::VertexArray& vertexArray, Shader& shader, Murk::IndexBuffer& indexBuffer) const;
	private:
		glm::vec4 clearColor;
	};
}