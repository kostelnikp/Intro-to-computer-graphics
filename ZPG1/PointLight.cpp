#include "PointLight.h"

PointLight::PointLight()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	attenuation.constant = 1.0f;
	attenuation.linear = 0.3f;
	attenuation.quadratic = 3.f;
	type = 1;
}

void PointLight::setAttenuation(float constant, float linear, float quadratic)
{
	this->attenuation.constant = constant;
	this->attenuation.linear = linear;
	this->attenuation.quadratic = quadratic;
	notifyObservers();
}

void PointLight::setPosition(const glm::vec3& newPosition)
{
	this->position = newPosition;
	notifyObservers();
}

Attenuation PointLight::getAttenuation() const
{
	return attenuation;
}

glm::vec3 PointLight::getPosition() const
{
	return position;
}

void PointLight::notifyObservers()
{
	for (ObserverInterface* observer : observers) {
		observer->update(2);                            // 2 - Light - position
		observer->update(3);                            // 3 - Light - color
		observer->update(4);                            // 4 - Light - attenuation
	}
}
