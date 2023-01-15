#include "Renderer.h"
#include "PixelEditor.h"
#include "FrogEngineFileParser.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "Transform.h"
#include <Camera.h>
#include <Events.h>

using namespace FrogEngine;

Renderer* renderer;
VertexBuffer *vertexBuffer;
VertexArray *vertexArray;
IndexBuffer *indexBuffer;
Shader* shader;
BufferLayout bufferlayout;

float verteces[]
{
	-0.5f, -0.5f, //bottom left
	-0.5f, 0.5f, //up left
	0.5f, 0.5f, //up right
	 0.5f, -0.5f, //bottom right
};
unsigned int drawOrder[]
{
	0, 1, 2,
	0, 2, 3
};

void PixelEditor::OnStart()
{
	 renderer = new Renderer();
	 vertexBuffer = new VertexBuffer(verteces, sizeof(verteces));
	 bufferlayout = BufferLayout();

	 bufferlayout.Push<float>(2); //positions
	 indexBuffer = new IndexBuffer(drawOrder, sizeof(drawOrder));
	 vertexArray = new VertexArray(*vertexBuffer, bufferlayout);
	 shader = new Shader(ParseFile("Color_v.shader"), ParseFile("Color_f.shader"));
	 shader->Bind();
	 shader->SetMatrix4f("u_MVP", glm::mat4(1));
	 shader->SetUniform4f("u_Color", 1.0f, 1.0f, 0.5f, 1.0f);
	 shader->Unbind();
	renderer->SetClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
}
void PixelEditor::OnUpdate()
{
	renderer->Clear();
	renderer->Draw(FrogEngine::Triangles, *vertexArray, *shader, *indexBuffer);
}
void PixelEditor::OnWindowResize(int width, int height)
{

	
}
void PixelEditor::OnClose()
{
	delete vertexArray;
	delete vertexBuffer;
	delete indexBuffer;
	delete shader;
	delete renderer;
}