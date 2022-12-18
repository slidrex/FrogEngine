#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>
#include <Transform.h>
#include <Camera.h>


using namespace FrogEngine;

Transform* transform;
VertexArray *vao;
VertexBuffer* vbo;
IndexBuffer* ibo;
Shader* shader;
Camera* camera;


Quad* quad;

unsigned int indeces[6]
{
	0, 1, 2,
	0, 2, 3
};

Renderer* renderer;

void HelloTriangle::PreRender()
{
	camera = new Camera(glm::vec3(0), -1.0f, 1.0f, -1.0f, 1.0f);
	
	transform = new Transform(glm::vec3(0), glm::vec3(1), glm::vec3(0));
	quad = CreateQuad(0.0f, 0.0f, 1.0f, 1.0f);
	
	vbo = new VertexBuffer(sizeof(Vertex2f) * 4);
	vbo->Bind();
	BufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	vao = new VertexArray(*vbo, layout);
	vao->Bind();
	shader = new Shader(ParseFile("Basicv.shader"), ParseFile("Basicf.shader"));
	shader->Bind();
	quad->SetTexture("images/img.jpg", 0, *shader, "u_TexturePixels");
	ImGuiContext* context = ImGui::CreateContext();
	ImGui::SetCurrentContext(context);
	ImGui_ImplGlfwGL3_Init(Window, true);

	ImGui::StyleColorsDark();

	ibo = new IndexBuffer(indeces, 6);
	shader->Unbind();
}
void HelloTriangle::RenderUpdate(float deltaTime)
{
	renderer->Clear();
	
	ImGui_ImplGlfwGL3_NewFrame();


	shader->Bind();
	vbo->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad->verteces), quad->verteces);
	if(Events::IsKeyPressed(GLFW_KEY_X))
	{
		transform->rotation.x += deltaTime;
	}
	if (Events::IsKeyPressed(GLFW_KEY_Y))
	{
		transform->rotation.y += deltaTime;
	}
	if (Events::IsKeyPressed(GLFW_KEY_Z))
	{
		transform->rotation.z += deltaTime;
	}

	ImGui::Text("Cat Transform");
	ImGui::SliderFloat2("Position", &transform->position.x, -1.0f, 1.0f);
	ImGui::SliderFloat2("Scale", &transform->scale.x, -1.0f, 1.0f);
	ImGui::SliderAngle("ZRoatation", &transform->rotation.z, -360.0f, 360.0f);
	


	shader->SetMatrix4f("u_MVP", camera->GetCameraProjection() * transform->GetModelProjection());
	renderer->Draw(*vao, *ibo, *shader);

	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

}
void HelloTriangle::OnClose()
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
}
void HelloTriangle::OnWindowResize(int width, int height)
{
	glViewport(0, 0, width, height);
	float aspectRatio = Events::GetAspectRatio();
	camera->m_SourceProejction = glm::vec4(-1.0f * aspectRatio, 1.0f * aspectRatio, -1.0f, 1.0f);
}
void HelloTriangle::OnMouseScrolling(double offset)
{

}