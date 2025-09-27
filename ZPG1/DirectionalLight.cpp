#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	direction = glm::vec3(0.0f, 0.0f, 0.0f);
	type = 3;

}

void DirectionalLight::setDirection(const glm::vec3& newDirection)
{
	this->direction = newDirection;
	notifyObservers();
}

glm::vec3 DirectionalLight::getDirection() const
{
	return direction;
}

void DirectionalLight::notifyObservers()
{
	for (ObserverInterface* observer : observers) {
		observer->update(3);                            // 3 - Light - color
		observer->update(6);                            // 6 - Light - direction
	}
}
