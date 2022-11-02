#include "glew.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glfw3.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

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