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
		static void SetClearColor(glm::vec4 color);
		static void Clear();
		static void SetPixelSize(float size) { glPointSize(size); };
		static void SetLineSize(float size) { glLineWidth(size); };
		static void Draw(RenderMode renderMode, Murk::VertexArray& vertexArray, Shader& shader, Murk::IndexBuffer& indexBuffer);
	private:
		Renderer();
		static Renderer s_Instance;
		glm::vec4 clearColor;
	};
}