#pragma once
#include "Renderer.h"
#include "Shapes2D.h"
#include "Shapes3D.h"
#include <vector>

namespace Murk
{
	struct RenderStackElement
	{
		Shader* shader;
		IndexBuffer* indexBuffer;
		VertexArray *vertexArray;
	};
	class RenderStack
	{
	private:
	public:
		std::vector<RenderStackElement*> m_RenderElements;
		RenderStack();
		RenderStackElement* PushRenderElement(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, IndexBuffer* ibo, VertexArray* vao);
		RenderStackElement* PushRenderElement(const std::string &vertexShaderSource, const std::string &fragmentShaderSource, Shape3D* shape);
		void DrawStack() const;
	};
}