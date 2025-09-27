#pragma once
#include "TransformationComponent.h"

class Translation : public TransformationComponent
{
private:
	glm::vec3 translation;

public:
	Translation(const glm::vec3& translation);
	glm::mat4 getComponentMatrix() override;
};
