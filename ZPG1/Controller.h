#pragma once

#include "Camera.h"
#include "Application.h"
#include <GLFW/glfw3.h>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */



class Application; 
class Controller
{
private:
	Camera* camera;
	Application* app;
	bool firstMouse;
	float lastX;
	float lastY;
	bool cursorEnabled;

public:
	Controller(Camera* camera, Application* app);
	void processInput(GLFWwindow* window);
	void processMouse(float alphaOffset, float fiOffset);
	glm::vec3 getWorldPositionFromMouse(GLFWwindow* window);

};

