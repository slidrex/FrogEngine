#include "Renderer.h"
#include "Log.h"
#include "ErrorChecking.h"

int main()
{
	if (!glfwInit())
	{
		FROG_CRITICAL("GLEW is not setup.");
		return -1;
	}
	glm::vec2 windowSize = glm::vec2(640, 480);
	GLFWwindow* window;
	window = glfwCreateWindow((int)windowSize.x, (int)windowSize.y, "FrogEngine", NULL, NULL);

	float verticies[8]
	{
		0.0, 0.0,
		0.0, 240,
		240, 240,
		240, 0
	};
	unsigned int indecies[6]
	{
		0, 1, 2,
		2, 3, 0
	};
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) FROG_CRITICAL("GLEW is not setup.");
	FrogEngine::InitDebugger();
	
	FrogEngine::Renderer renderer;

	FrogEngine::VertexBuffer vertexBuffer(verticies, sizeof(verticies));
	FrogEngine::VertexArray vertexArray(vertexBuffer, 2);
	FrogEngine::IndexBuffer indexBuffer(indecies, 6);
	
	glm::mat4 proj = glm::ortho(0.0f, (float)windowSize.x, 0.0f, (float)windowSize.y);
	FrogEngine::Shader shader("Basic.vert", "Basic.frag");
	
	while (glfwWindowShouldClose(window) == false)
	{
		renderer.Clear();
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.7f, 1.0f, 0.7f, 1.0f);
		shader.SetMatrix4f("u_MVP", proj);
		renderer.Draw(FrogEngine::RenderMode::Triangles, vertexArray, indexBuffer, shader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}