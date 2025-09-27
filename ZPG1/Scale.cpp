#include "Scale.h"

Scale::Scale(float scaleValue)
{
	this->scaleValue = scaleValue;
}

glm::mat4 Scale::getComponentMatrix()
{
	return glm::scale(glm::mat4(1.0f), glm::vec3(scaleValue));
}
