#include "Rotation.h"

Rotation::Rotation(const glm::vec3& rotation, float rotationAngle)
{
	this->rotation = rotation;
	this->rotationAngle = rotationAngle;
}

glm::mat4 Rotation::getComponentMatrix()
{
	return glm::rotate(glm::mat4(1.0f), rotationAngle, rotation);
}

