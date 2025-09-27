#pragma once
#include "TransformationComponent.h"

class Scale : public TransformationComponent
{
private:
	float scaleValue;

public:
	Scale(float scaleValue);
	glm::mat4 getComponentMatrix() override;
};
