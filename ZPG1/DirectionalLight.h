#pragma once

#include "Light.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class DirectionalLight : public Light
{
private:
	glm::vec3 direction;
public:
	DirectionalLight();

	void setDirection(const glm::vec3& newDirection);
	glm::vec3 getDirection() const;

	void notifyObservers() override;

};

