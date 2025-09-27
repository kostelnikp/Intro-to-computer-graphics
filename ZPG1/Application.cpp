#include "Application.h"

Application::Application()
{
	window = nullptr;
	camera = new Camera(glm::vec3(0.0f, 1.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	pointLight = new PointLight();
	pointLight2 = new PointLight();
	pointLight3 = new PointLight();
	pointLight4 = new PointLight();
	spotLight = new SpotLight();
	directionalLight = new DirectionalLight();
	

	controller = new Controller(camera, this);

	scene1 = nullptr;
	scene2 = nullptr;
	scene3 = nullptr;
	scene4 = nullptr;
	scene5 = nullptr;
	scene6 = nullptr;
	currentSceneIndex = 0;
}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
	if (app && app->camera) {
		float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
		app->camera->setPerspective(width, height);
	}
}

Scene* Application::getCurrentScene() {
	switch (currentSceneIndex) {
	case 0:
		return scene1;
	case 1:
		return scene2;
	case 2:
		return scene3;
	case 3:
		return scene4;
	case 4:
		return scene5;
	case 5:
		return scene6;
	default:
		return nullptr; 
	}
}



void Application::initialization()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewExperimental = GL_TRUE;
	glewInit();



	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetWindowUserPointer(window, this);


	pointLight->setPosition(glm::vec3(20.0f, 1.0f, 15.0f));
	pointLight->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//pointLight->setAttenuation(1.0f, 0.3f, 0.3f);
	pointLight->setAttenuation(1.0f, 0.009f, 0.03f);


	pointLight2->setPosition(glm::vec3(20.0f, 1.0f, 25.0f));
	pointLight2->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	pointLight2->setAttenuation(1.0f, 0.009f, 0.03f);

	pointLight3->setPosition(glm::vec3(-2.0f, 1.0f, -6.0f));
	pointLight3->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
	pointLight3->setAttenuation(1.0f, 0.009f, 0.03f);

	pointLight4->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	pointLight4->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	pointLight4->setAttenuation(1.0f, 0.009f, 0.03f);

	spotLight->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	spotLight->setCutOff(glm::cos(glm::radians(12.5f)));
	spotLight->setAttenuation(1.0f, 0.009f, 0.032f);
	//spotLight->setAttenuation(.2f, 0.0029f, 0.0032f);


	directionalLight->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
	directionalLight->setDirection(glm::vec3(1.0f, 0.0f, 0.0f));

	camera->addObserver(spotLight);
	spotLight->addCamera(camera);

	scene1 = new Scene();
	scene1->initScene1();
	//scene1->addObserver(camera);

	scene2 = new Scene();
	scene2->initScene2();
	scene2->addObserver(camera);
	//scene2->addObserver(pointLight);
	//scene2->addObserver(pointLight3);
	scene2->addObserver(spotLight);
	scene2->addObserver(directionalLight);
	

	scene3 = new Scene();
	scene3->initScene3();
	scene3->addObserver(camera);
	scene3->addObserver(pointLight4);
	scene3->addObserver(spotLight);


	scene4 = new Scene();
	scene4->initScene4();
	scene4->addObserver(camera);
	scene4->addObserver(pointLight4);
	scene4->addObserver(spotLight);

	scene5 = new Scene();
	scene5->initScene5();
	scene5->addObserver(camera);

	scene6 = new Scene();
	scene6->initScene6();
	scene6->addObserver(camera);
	scene6->addObserver(spotLight);
	scene6->addObserver(pointLight);
	scene6->addObserver(pointLight2);
	scene6->addObserver(pointLight3);
	scene6->addObserver(directionalLight);



	camera->getProjectionMatrix();
}

void Application::run()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		switch (currentSceneIndex) {
		case 0:
			scene1->draw();
			break;
		case 1:
			scene2->draw();
			break;
		case 2:
			scene3->draw();
			break;
		case 3:
			scene4->draw();
			break;
		case 4:
			if (skybox)
				scene5->drawSkybox();
			else
				scene5->drawCubeSkybox();
			scene5->draw();
			break;
		case 5:
			if (skybox)
				scene6->drawSkybox();
			else
				scene6->drawCubeSkybox();
			scene6->draw();
			break;
		}

		double xpos, ypos;
		glfwGetCursorPos(window, &ypos, &xpos);
		controller->processInput(window);
		controller->processMouse((float)xpos, (float)ypos);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void Application::switchScene(int newIndex)
{
	double currentTime = glfwGetTime();
	if (currentTime - lastSwitchTime >= switchCooldown) {
		if (newIndex < 0) newIndex = 5;
		if (newIndex > 5) newIndex = 0;
		currentSceneIndex = newIndex;
		lastSwitchTime = currentTime;
	}
	camera->setBasePosition();
}

int Application::getCurrentSceneIndex()
{
	return currentSceneIndex;
}

void Application::changeSkybox()
{
	skybox = !skybox;
}
