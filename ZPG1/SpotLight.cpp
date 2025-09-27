#include "SpotLight.h"

SpotLight::SpotLight()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	attenuation.constant = 1.0f;
	attenuation.linear = 0.3f;
	attenuation.quadratic = 3.f;
	cutOff = 0.f;
	direction = glm::vec3(0.0f, 0.0f, 0.0f);
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	type = 2;
}

void SpotLight::setAttenuation(float constant, float linear, float quadratic)
{
	this->attenuation.constant = constant;
	this->attenuation.linear = linear;
	this->attenuation.quadratic = quadratic;
	notifyObservers();
}

void SpotLight::setCutOff(float newCutOff)
{
	this->cutOff = newCutOff;
	notifyObservers();
}


Attenuation SpotLight::getAttenuation() const
{
	return attenuation;
}

float SpotLight::getCutOff() const
{
	return cutOff;
}

glm::vec3 SpotLight::getDirection() const
{
	return direction;
}

glm::vec3 SpotLight::getPosition() const
{
	return position;
}

void SpotLight::addCamera(Camera* camera)
{
	this->camera = camera;
}

void SpotLight::update(int updateType)
{
	if (updateType == 7)
	{
		this->direction = camera->getTarget();
		notifyObservers();
	}
	else if (updateType == 8)
	{
		this->position = camera->getPosition();
		notifyObservers();
	}
}

void SpotLight::notifyObservers()
{
	for (ObserverInterface* observer : observers) {
		observer->update(2);                            // 2 - Light - position
		observer->update(3);                            // 3 - Light - color
		observer->update(4);                            // 4 - Light - attenuation
		observer->update(5);                            // 5 - Light - cutOff
		observer->update(6);							// 6 - Light - direction
	}
}
