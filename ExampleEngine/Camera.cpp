#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

FrogEngine::Camera::Camera(glm::vec3 startPosition, float leftProjection, float rightProjection, float bottomProjection, float topProjection)
{
	m_Position = startPosition;
	m_Projection.x = leftProjection;
	m_Projection.y = rightProjection;
	m_Projection.z = bottomProjection;
	m_Projection.w = topProjection;
}
void FrogEngine::Camera::Move(glm::vec3 delta)
{
	m_Position -= delta;
}
void FrogEngine::Camera::Zoom(float scale)
{
	m_Projection += glm::vec4(-scale, scale, -scale, scale);
}
glm::mat4 FrogEngine::Camera::GetCameraProjection()
{
	return glm::ortho(m_Projection.x, m_Projection.y, m_Projection.z, m_Projection.w) * glm::translate(glm::mat4(1), m_Position);
}