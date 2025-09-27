#pragma once
#include "TransformationComponent.h"

class Rotation : public TransformationComponent
{
protected:
	glm::vec3 rotation;
	float rotationAngle;

public:
	Rotation(const glm::vec3& rotation, float rotationAngle);
	glm::mat4 getComponentMatrix() override;

};
