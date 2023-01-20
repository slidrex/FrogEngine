#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Log.h"

Murk::Camera::Camera(glm::vec3 startPosition, glm::vec3 startRotation, float leftProjection, float rightProjection, float bottomProjection, float topProjection)
{
	m_Position = startPosition;
	m_SourceProejction.x = leftProjection;
	m_SourceProejction.y = rightProjection;
	m_SourceProejction.z = bottomProjection;
	m_SourceProejction.w = topProjection;
	m_Rotation = startRotation;
	m_Projection = m_SourceProejction;
	m_ZoomLevel = glm::vec2(1.0f, 1.0f);
}
void Murk::Camera::Move(glm::vec3 delta)
{
	m_Position -= delta;
}
void Murk::Camera::Rotate(glm::vec3 delta)
{
	m_Rotation += delta;
	print(m_Rotation.z);
}
void Murk::Camera::SetZoomLevel(float xZoom, float yZoom)
{
	m_ZoomLevel = glm::vec2(xZoom, yZoom);
	m_Projection = m_SourceProejction * glm::vec4(-xZoom, xZoom, -yZoom, yZoom);
	print(m_Projection.x);
}
glm::mat4 Murk::Camera::GetCameraProjection()
{
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), m_Rotation.x, glm::vec3(1, 0, 0)) * glm::rotate(glm::mat4(1), m_Rotation.y, glm::vec3(0, 1, 0)) * glm::rotate(glm::mat4(1), m_Rotation.z, glm::vec3(0, 0, 1));
	return glm::ortho(m_Projection.x, m_Projection.y, m_Projection.z, m_Projection.w) * glm::translate(glm::mat4(1), m_Position) * rotationMatrix;
}