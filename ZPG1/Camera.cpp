#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
{
	this->position = position;
	this->target = target;
	this->up = up;
	width = 800;
	height = 600;
}

void Camera::moveForward()
{
	position += (glm::normalize(target) * 0.15f);
	notifyObservers();
}

void Camera::moveBackward()
{
	position -= (glm::normalize(target) * 0.15f);
	notifyObservers();
}

void Camera::moveLeft()
{
	position -= (glm::normalize(glm::cross(target, up)) * 0.15f);	
	notifyObservers();
}

void Camera::moveRight()
{
	position += (glm::normalize(glm::cross(target, up)) * 0.15f);
	notifyObservers();
}

void Camera::rotate(float alphaOffset, float fiOffset)
{
	static float fi = -90.0f;
	static float alpha = .0f;


	alpha -= alphaOffset;
	fi -= fiOffset;

	if (alpha > 89.0f)
		alpha = 89.0f;
	if (alpha < -89.0f)
		alpha = -89.0f;

	target.x = cos(glm::radians(fi)) * cos(glm::radians(alpha));
	target.y = sin(glm::radians(alpha));
	target.z = sin(glm::radians(fi)) * cos(glm::radians(alpha));


	notifyObservers();
}

void Camera::setBasePosition()
{

	position = glm::vec3(0, 1, 10);
	target = glm::vec3(0, 0, 0);
	up = glm::vec3(0, 1, 0);
}

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::vec3 Camera::getTarget()
{
	return target;
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getProjectionMatrix()
{
	return glm::perspective(45.f, width/height, 0.1f, 100.0f);
}

void Camera::setPerspective(float width, float height) {
	this->width = width;
	this->height = height;
	notifyObservers();
}

glm::vec2 Camera::getResolution()
{
	return glm::vec2(width, height);
}



void Camera::addObserver(ObserverInterface* observer)
{
	observers.push_back(observer);
}

void Camera::notifyObservers()
{
	for (ObserverInterface* observer : observers)
	{
		observer->update(0);					// 0 - Camera - view matrix
		observer->update(1);					// 1 - Camera - projection matrix
		observer->update(7);					// 7 - Camera - view direction
		observer->update(8);					// 8 - Camera - position
	}
}
