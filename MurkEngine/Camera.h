#pragma once
#include "glm/glm.hpp"

namespace Murk
{
	class Camera
	{
	public:
		Camera(glm::vec3 startPosition, glm::vec3 startRotation, float leftProjection, float rightProjection, float bottomProjection, float topProjection);
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		glm::vec4 m_Projection;
		glm::vec4 m_SourceProejction;
		glm::vec2 m_ZoomLevel;
		glm::mat4 GetCameraProjection();
		void Move(glm::vec3 delta);
		void Rotate(glm::vec3 dRotating);
		void SetZoomLevel(float xZoom, float yZoom);
	};
}