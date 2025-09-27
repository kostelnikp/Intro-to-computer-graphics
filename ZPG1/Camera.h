#pragma once

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "ObserverInterface.h"
#include "SubjectInterface.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ShaderProgram;
class Camera : public SubjectInterface
{
private:
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;


	float width;
	float height;

public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);

	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void rotate(float alphaOffset, float fiOffset);

	void setBasePosition();
	glm::vec3 getPosition();
	glm::vec3 getTarget();
	void setPerspective(float width, float height);

	glm::vec2 getResolution();


	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	
	void addObserver(ObserverInterface* observer) override;
	void notifyObservers() override;


};

