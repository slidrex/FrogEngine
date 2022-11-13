#include <FrogEngine.h>
#include "HelloTriangle.h"
#include <FrogEngineFileParser.h>
#include <ctime>
#include <cstdlib>

using namespace FrogEngine;

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

VertexBuffer* vertexBuffer;
VertexArray* vertexArray;
IndexBuffer* indexBuffer;
Shader* shader;
Renderer* renderer;
float position = 0;
bool raises;
bool topdownMove;
float accelerationMultiplier = 1;

float AccelerationIncreaseRate = 0.03f;
float TriangleSpeed = 0.003;

void HelloTriangle::PreRender()
{
	vertexBuffer = new VertexBuffer(positions, sizeof(positions));
	vertexArray = new VertexArray(*vertexBuffer, 2);
	indexBuffer = new IndexBuffer(indeces, sizeof(indeces));

	renderer = new Renderer();
	shader = new Shader(ParseFile("Basic.vert"), ParseFile("Basic.frag"));
	std::srand(time(NULL));
	topdownMove = std::rand() % 2;
	raises = std::rand() % 2;
}
void HelloTriangle::RenderUpdate()
{
	(*renderer).Clear();
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f);
	glm::vec3 moveVector(0, 0, 0);

	HandleCollisions(moveVector);
	SpeedCalculation();

	glm::mat4 viewMat = glm::translate(glm::mat4(1), moveVector);
	
	(*shader).SetMatrix4f("u_MVP", viewMat * projection);
	(*shader).SetUniform4f("u_Color", 0.5f, 0.5f, 1, 1);
	(*renderer).Draw(RenderMode::Triangles, *vertexArray, *indexBuffer, *shader);
}
void HelloTriangle::HandleCollisions(glm::vec3 &moveVector)
{
	if (topdownMove)
	{
		moveVector.y = position;
		if (moveVector.y < -1)
		{
			accelerationMultiplier = 1;
			raises = true;
		}
		if (moveVector.y > 0.5)
		{
			accelerationMultiplier = 1;
			raises = false;
		}
	}
	else
	{
		moveVector.x = position;
		if (moveVector.x < -0.5)
		{
			accelerationMultiplier = 1;
			raises = true;
		}
		if (moveVector.x > 0.5)
		{
			accelerationMultiplier = 1;
			raises = false;
		}
	}
}
void HelloTriangle::SpeedCalculation()
{
	accelerationMultiplier += AccelerationIncreaseRate;
	if (raises == true) position += TriangleSpeed * accelerationMultiplier;
	else position -= TriangleSpeed * accelerationMultiplier;

}
void HelloTriangle::OnClose()
{
	delete vertexBuffer;
	delete vertexArray;
	delete shader;
	delete renderer;
}
