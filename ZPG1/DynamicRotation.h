#pragma once

#include "Rotation.h"

class DynamicRotation : public Rotation
{
private:
	float angleIncrement;
public:
	DynamicRotation(float angleIncrement, const glm::vec3& rotation, float rotationAngle);

	glm::mat4 getComponentMatrix() override;

};

