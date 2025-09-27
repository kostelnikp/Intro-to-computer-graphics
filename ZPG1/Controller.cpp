#include "Controller.h"

Controller::Controller(Camera* camera, Application* app)
{
	this->camera = camera;
	this->app = app;
	firstMouse = true;
	lastX = 400;
	lastY = 300;
	cursorEnabled = true;
}

void Controller::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera->moveForward();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->moveBackward();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->moveLeft();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->moveRight();
	}

	static bool wasPPressed = false;
	bool isPPressed = (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS);
	if (isPPressed && !wasPPressed) {
		app->changeSkybox();
	}
	wasPPressed = isPPressed;

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		app->switchScene(app->getCurrentSceneIndex() - 1);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		app->switchScene(app->getCurrentSceneIndex() + 1);
	}
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		static double lastToggleTime = 0;
		double currentTime = glfwGetTime();
		if (currentTime - lastToggleTime >= 0.3) {
			if (cursorEnabled) {
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			}
			else {
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			}
			cursorEnabled = !cursorEnabled;
			lastToggleTime = currentTime;
		}
	}
	static bool wasLeftMousePressed = false;
	bool isLeftMousePressed = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
	if (isLeftMousePressed && !wasLeftMousePressed) {
		glm::vec3 pos = getWorldPositionFromMouse(window);
		app->getCurrentScene()->addTree(pos);
	}
	wasLeftMousePressed = isLeftMousePressed;


	static bool wasBPressed = false;
	bool isBPressed = (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS);
	if (isBPressed && !wasBPressed) {
		glm::vec3 point = getWorldPositionFromMouse(window);
		app->getCurrentScene()->addPointToBezierCurve(point);
	}
	wasBPressed = isBPressed;

	static bool wasKPressed = false;
	bool isKPressed = (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS);
	if (isKPressed && !wasKPressed) {
		GLuint index;
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		int newy = camera->getResolution().y - (int)y;
		glReadPixels(static_cast<int>(x), newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

		app->getCurrentScene()->addBezierCurveToObject(index);


	}
	wasKPressed = isKPressed;

}

void Controller::processMouse(float alphaOffset, float fiOffset)
{
	if (firstMouse)
	{
		lastX = alphaOffset;
		lastY = fiOffset;
		firstMouse = false;
	}

	float xoffset = alphaOffset - lastX;
	float yoffset = lastY - fiOffset;
	lastX = alphaOffset;
	lastY = fiOffset;

	const float sensitivity = 0.2f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera->rotate(xoffset, yoffset);
}

glm::vec3 Controller::getWorldPositionFromMouse(GLFWwindow* window)
{
	GLbyte color[4];
	GLfloat depth;
	GLuint index;

	double x, y;
	glfwGetCursorPos(window, &x, &y);

	int newy = camera->getResolution().y - (int)y;

	glReadPixels(static_cast<int>(x), newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
	glReadPixels(static_cast<int>(x), newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
	glReadPixels(static_cast<int>(x), newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	glm::vec3 screenX = glm::vec3((float)x, (float)newy, depth);
	glm::mat4 view = camera->getViewMatrix();
	glm::mat4 projection = camera->getProjectionMatrix();
	glm::vec4 viewPort = glm::vec4(0, 0, camera->getResolution().x, camera->getResolution().y);

	glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);
	return pos;
}

