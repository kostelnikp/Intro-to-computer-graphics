#include "Application.h"

int main(void) {
	Application* app = new Application();

	app->initialization();
	app->run();


	return 0;
}
