#pragma once
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace FrogEngine
{
	enum RenderMode
	{
		Triangles = GL_TRIANGLES,
		Polygons = GL_POLYGON
	};
	class Renderer
	{
	public:
		void Clear() const;
		void Draw(RenderMode renderMode, FrogEngine::VertexArray& vertexArray, FrogEngine::IndexBuffer& indexBuffer, Shader& shader) const;
	};
}