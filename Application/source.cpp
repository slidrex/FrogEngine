#include <FrogEngine.h>
#include "HelloTriangle.h"
#include "ErrorCatcher.h"
#include <FrogEngineFileParser.h>
int main()
{
	float positions[6]
	{
		-0.5f, 0.0f,
		0.0, 0.5f,
		0.5f, 0.0f
	};
	unsigned int indeces[3]
	{
		0, 1, 2
	};
	//FrogEngine::EntryPoint* app = new FrogEngine::EntryPoint(new HelloTriangle());
	//(*app).Run();
	//delete app;
	glfwInit();
	GLFWwindow *window = glfwCreateWindow(640, 720, "test", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();
	FrogEngine::InitDebugger();
	FrogEngine::VertexBuffer* vertexBuffer = new FrogEngine::VertexBuffer(positions, sizeof(positions));
	FrogEngine::VertexArray* vertexArray = new FrogEngine::VertexArray(*vertexBuffer, 2);
	FrogEngine::IndexBuffer* indexBuffer = new FrogEngine::IndexBuffer(indeces, sizeof(indeces));
	FrogEngine::Shader shader(FrogEngine:: ParseFile("Basic.frag"), FrogEngine::ParseFile("Basic.vert"));
	shader.SetUniform4f("u_Color", 0.5f, 0.5f, 1, 1);

	FrogEngine::Renderer* rend = new FrogEngine::Renderer();
	
	//(*shader).SetMatrix4f("u_MVP", projection);

	while(glfwWindowShouldClose(window) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		(*rend).Draw(FrogEngine::RenderMode::Triangles, *vertexArray, *indexBuffer, shader);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	
	return 0;
}
