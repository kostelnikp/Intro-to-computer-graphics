#include "DynamicRotation.h"

DynamicRotation::DynamicRotation(float angleIncrement, const glm::vec3& rotation, float rotationAngle) : Rotation(rotation, rotationAngle)
{
	this->angleIncrement = angleIncrement;
	this->rotation = rotation;
	this->rotationAngle = rotationAngle;
}

glm::mat4 DynamicRotation::getComponentMatrix()
{
	rotationAngle += angleIncrement;
	return glm::rotate(glm::mat4(1.0f), rotationAngle, rotation);
}
