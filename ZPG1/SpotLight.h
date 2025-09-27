#pragma once

#include "Light.h"
#include "Camera.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class SpotLight : public Light, public ObserverInterface
{
private:
	Attenuation attenuation;
	float cutOff;
	glm::vec3 direction;
	glm::vec3 position;
	Camera* camera;
public:
	SpotLight();

	void setAttenuation(float constant, float linear, float quadratic);
	void setCutOff(float newCutOff);

	Attenuation getAttenuation() const;
	float getCutOff() const;
	glm::vec3 getDirection() const;
	glm::vec3 getPosition() const;

	void addCamera(Camera* camera);

	void notifyObservers() override;
	void update(int updateType) override;

};

