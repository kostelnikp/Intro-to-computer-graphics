#pragma once

#include "Light.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */

class PointLight : public Light
{
private:
	glm::vec3 position;
	Attenuation attenuation;
public:
	PointLight();

	void setAttenuation(float constant, float linear, float quadratic);
	void setPosition(const glm::vec3& newPosition);


	Attenuation getAttenuation() const;
	glm::vec3 getPosition() const;

	void notifyObservers() override;

};

