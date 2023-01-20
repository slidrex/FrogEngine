#pragma once
#include "Renderer.h"
#include "Shapes2D.h"
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
		std::vector<RenderStackElement*> m_RenderElements;
		Renderer *m_Renderer;
	public:
		RenderStack(Renderer *renderer);
		RenderStackElement* PushRenderElement(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, IndexBuffer* ibo, VertexArray* vao);
		RenderStackElement* PushRenderElement(const std::string &vertexShaderSource, const std::string &fragmentShaderSource, Shape2D* shape);
		void DrawStack() const;
	};
}