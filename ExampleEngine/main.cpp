#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Renderer.h"
#include "Log.h"

int main()
{
	if (!glfwInit())
	{
		FROG_CRITICAL("GLEW is not setup.");
		return -1;
	}

	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "FrogEngine", NULL, NULL);

	float verticies[8]
	{
		-0.5f, -0.5f,
		-0.5f, 0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f
	};
	unsigned int indecies[6]
	{
		0, 1, 2,
		2, 3, 0
	};
	
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) FROG_CRITICAL("GLEW is not setup.");
	
	FrogEngine::Renderer renderer;

	FrogEngine::VertexBuffer vertexBuffer(verticies, sizeof(verticies));
	FrogEngine::VertexArray vertexArray(vertexBuffer, 2);
	FrogEngine::IndexBuffer indexBuffer(indecies, 6);
	

	FrogEngine::Shader shader("Basic.vert", "Basic.frag");
	
	
	while (glfwWindowShouldClose(window) == false)
	{
		renderer.Clear();
		
		shader.SetUniform4f("u_Color", 0.7f, 1.0f, 0.7f, 1.0f);
		renderer.Draw(FrogEngine::RenderMode::Triangles, vertexArray, indexBuffer, shader);
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}