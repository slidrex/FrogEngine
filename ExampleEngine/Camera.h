#pragma once
#include "glm/glm.hpp"

namespace FrogEngine
{
	class Camera
	{
	public:
		Camera(glm::vec3 startPosition, float leftProjection, float rightProjection, float bottomProjection, float topProjection);
		glm::vec3 m_Position;
		glm::vec4 m_Projection;
		glm::vec4 m_SourceProejction;
		glm::vec2 m_ZoomLevel;
		glm::mat4 GetCameraProjection();
		void Move(glm::vec3 delta);
		void SetZoomLevel(float xZoom, float yZoom);
	};
}