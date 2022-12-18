#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Log.h"

FrogEngine::Camera::Camera(glm::vec3 startPosition, float leftProjection, float rightProjection, float bottomProjection, float topProjection)
{
	m_Position = startPosition;
	m_SourceProejction.x = leftProjection;
	m_SourceProejction.y = rightProjection;
	m_SourceProejction.z = bottomProjection;
	m_SourceProejction.w = topProjection;
	m_Projection = m_SourceProejction;
	m_ZoomLevel = glm::vec2(1.0f, 1.0f);
}
void FrogEngine::Camera::Move(glm::vec3 delta)
{
	m_Position -= delta;
}
void FrogEngine::Camera::SetZoomLevel(float xZoom, float yZoom)
{
	m_ZoomLevel = glm::vec2(xZoom, yZoom);
	m_Projection = m_SourceProejction * glm::vec4(-xZoom, xZoom, -yZoom, yZoom);
	print(m_Projection.x);
}
glm::mat4 FrogEngine::Camera::GetCameraProjection()
{
	return glm::ortho(m_Projection.x, m_Projection.y, m_Projection.z, m_Projection.w) * glm::translate(glm::mat4(1), m_Position);
}