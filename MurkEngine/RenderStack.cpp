#include "RenderStack.h"

Murk::RenderStack::RenderStack(Renderer *renderer)
{
	m_Renderer = renderer;
}

Murk::RenderStackElement* Murk::RenderStack::PushRenderElement(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, IndexBuffer* ibo, VertexArray* vao)
{
	Murk::RenderStackElement *element = new Murk::RenderStackElement();
	Murk::Shader* shader = new Murk::Shader(vertexShaderSource, fragmentShaderSource);
	element->indexBuffer = ibo;
	element->vertexArray = vao;
	element->shader = shader;
	m_RenderElements.push_back(element);
	return element;
}

Murk::RenderStackElement* Murk::RenderStack::PushRenderElement(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, Shape2D* shape)
{
	Murk::IndexBuffer *ibo = new Murk::IndexBuffer(shape->indeces, shape->indexCount);
	
	Murk::VertexBuffer* vbo = new Murk::VertexBuffer((const void*)shape->verteces, sizeof(Vertex2f) * shape->vertexCount);
	Murk::BufferLayout layout;
	layout.Push<float>(2); //pos
	layout.Push<float>(2); //tex
	Murk::VertexArray* vao = new Murk::VertexArray(*vbo, layout);
	return PushRenderElement(vertexShaderSource, fragmentShaderSource, ibo, vao);
}

void Murk::RenderStack::DrawStack() const
{
	for(int i = 0; i < m_RenderElements.size(); i++)
	{
		RenderStackElement* el = m_RenderElements[i];

		m_Renderer->Draw(Murk::Triangles, *el->vertexArray, *el->shader, *el->indexBuffer);
	}
}
