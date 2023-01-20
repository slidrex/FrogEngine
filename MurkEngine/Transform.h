#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Murk
{
	struct Transform
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		Transform(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _rotation)
		{
			position = _position;
			rotation = _rotation;
			scale = _scale;
		}
		glm::mat4 GetModelProjection()
		{
			return glm::scale(glm::mat4(1), scale) * glm::translate(glm::mat4(1), position) * glm::rotate(glm::mat4(1), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(glm::mat4(1), rotation.y, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(glm::mat4(1), rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		}
	};
}