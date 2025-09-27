#pragma once

#include "Scene.h"
#include "Controller.h"
#include "Camera.h"
#include "Light.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionalLight.h"

#include <GLFW/glfw3.h>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */



class Controller;
class Application {
private:
	GLFWwindow* window;

	Scene* scene1;
	Scene* scene2;
	Scene* scene3;
	Scene* scene4;
	Scene* scene5;
	Scene* scene6;
	int currentSceneIndex;

	Controller* controller;
	Camera* camera;
	PointLight* pointLight;
	PointLight* pointLight2;
	PointLight* pointLight3;
	PointLight* pointLight4;
	SpotLight* spotLight;
	DirectionalLight* directionalLight;


	double lastSwitchTime = 0;
	const double switchCooldown = 0.3;

	bool skybox = true;

public:
	Application();
	void initialization();
	void switchScene(int newIndex);
	void run();
	int getCurrentSceneIndex();
	void changeSkybox();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	Scene* getCurrentScene();



};
