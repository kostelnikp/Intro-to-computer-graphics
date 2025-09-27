#include "Scene.h"


Scene::Scene()
{
	constShader = nullptr;
	constShader2 = nullptr;
	constShader3 = nullptr;
	shaderProgram = nullptr;
	shaderProgram2 = nullptr;
	shaderProgram3 = nullptr;
	shaderProgram4 = nullptr;
	camera = nullptr;
	bezierCurve = new BezierCurve();
	drawableObjectsCount = 0;

}

void Scene::initScene1()
{
	constShader = new ConstShader("vertex_shader_test_scene.glsl", "fragment_shader_test_scene.glsl");

	float triangleVertices[] = {
	-0.5f,  -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	};

	ModelFactory* modelFactory = new ModelFactory();
	ModelInterface* modelTriangle = modelFactory->create(triangleVertices, sizeof(triangleVertices), 3);
	DrawableObject* drawableObject = new DrawableObject(modelTriangle, constShader);

	addDrawableObject(drawableObject);
}

void Scene::initScene2()
{
	int rotateObjectsCount = 5;

	shaderProgram = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_phong_more_lights.glsl");

	ModelFactory* modelFactory = new ModelFactory();
	ModelInterface* modelTree = modelFactory->create(tree, sizeof(tree), 92814);
	ModelInterface* modelBush = modelFactory->create(bushes, sizeof(bushes), 8730);
	ModelInterface* modelPlain = modelFactory->create(plain, sizeof(plain), 6);

	DrawableObject* drawableObject;
	TransformationComponent* transformationComponent;
	Material* material = new Material(0.075f, 0.8f, 1.0f);
	Material* material2 = new Material(0.2f, 0.6f, 0.9f);

	srand((time(0)));
	for (int j = 0; j < 100; j++) {
		float randomX = (rand() % 200 - 130) / 10.0f;
		float randomY = (rand() % 200 - 130) / 10.0f;
		float randomScale = (rand() % 26 + 5) / 100.0f;

		drawableObject = new DrawableObject(modelTree, shaderProgram);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		if (j < rotateObjectsCount) {
			transformationComponent = new DynamicRotation(0.025f, glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		}
		else {
			transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		}

		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setMaterial(material);
		addDrawableObject(drawableObject);
	}

	for (int j = 0; j < 100; j++) {
		float randomX = (rand() % 200 - 130) / 10.0f;
		float randomY = (rand() % 200 - 130) / 10.0f;
		float randomScale = (rand() % 26 + 15) / 100.0f;

		drawableObject = new DrawableObject(modelBush, shaderProgram);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setMaterial(material2);
		addDrawableObject(drawableObject);
	}

	drawableObject = new DrawableObject(modelPlain, shaderProgram);
	transformationComponent = new Scale(20.0f);
	drawableObject->addTransformationComponent(transformationComponent);

	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);
}


void Scene::initScene3() {
	shaderProgram = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_phong_more_lights.glsl");

	ModelFactory* modelFactory = new ModelFactory();
	ModelInterface* modelSphere = modelFactory->create(sphere, sizeof(sphere), 2880);

	DrawableObject* drawableObject;
	TransformationComponent* transformationComponent;

	Material* material = new Material(0.075f, 0.8f, 1.0f);
	Material* material2 = new Material(0.2f, 0.6f, 0.9f);


	drawableObject = new DrawableObject(modelSphere, shaderProgram);
	transformationComponent = new Translation(glm::vec3(0.0f, 2.5f, 0.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSphere, shaderProgram);
	transformationComponent = new Translation(glm::vec3(0.0f, -2.5f, 0.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material2);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSphere, shaderProgram);
	transformationComponent = new Translation(glm::vec3(-2.5f, 0.0f, 0.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSphere, shaderProgram);
	transformationComponent = new Translation(glm::vec3(2.5f, 0.0f, 0.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material2);
	addDrawableObject(drawableObject);
}


void Scene::initScene4()
{
	constShader = new ConstShader("vertex_shader_const.glsl", "fragment_shader_const.glsl");
	shaderProgram2 = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_phong_more_lights.glsl");
	shaderProgram3 = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_lambert.glsl");
	shaderProgram4 = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_blinn.glsl");

	ModelFactory* modelFactory = new ModelFactory();
	ModelInterface* modelSuziFlat = modelFactory->create(suziFlat, sizeof(suziFlat), 2904);

	DrawableObject* drawableObject;
	TransformationComponent* transformationComponent;
	Material* material = new Material(0.075f, 0.8f, 1.0f);

	drawableObject = new DrawableObject(modelSuziFlat, constShader);
	transformationComponent = new Translation(glm::vec3(7.5f, 0.0f, -5.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSuziFlat, shaderProgram2);
	transformationComponent = new Translation(glm::vec3(2.5f, 0.0f, -5.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSuziFlat, shaderProgram3);
	transformationComponent = new Translation(glm::vec3(-2.5f, 0.0f, -5.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelSuziFlat, shaderProgram4);
	transformationComponent = new Translation(glm::vec3(-7.5f, 0.0f, -5.0f));
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

}

void Scene::initScene5()
{
	int rotateObjectsCount = 5;
	constShader = new ConstShader("vertex_shader.glsl", "fragment_shader.glsl");
	constShader2 = new ConstShader("vertex_shader_texture.glsl", "fragment_shader_texture.glsl");
	constShader3 = new ConstShader("vertex_shader_skycube.glsl", "fragment_shader_skycube.glsl");

	ModelFactory* modelFactory = new ModelFactory();
	ModelInterface* modelTree = modelFactory->create(tree, sizeof(tree), 92814);
	ModelInterface* modelBush = modelFactory->create(bushes, sizeof(bushes), 8730);

	ModelSkycubeFactory* modelSkycubeFactory = new ModelSkycubeFactory();
	ModelInterface* modelSkyCube = modelSkycubeFactory->create(skycube, sizeof(skycube), 36);

	ModelTextureFactory* modelTextureFactory = new ModelTextureFactory();
	ModelInterface* modelPlain = modelTextureFactory->create(plaintexture, sizeof(plaintexture), 6);

	ModelObjectFactory* modelObjectFactory = new ModelObjectFactory();
	ModelInterface* modelHouse = modelObjectFactory->create("house.obj");

	DrawableObject* drawableObject;
	TransformationComponent* transformationComponent;

	Material* material = new Material(0.075f, 0.8f, 1.0f);
	Material* material2 = new Material(0.2f, 0.6f, 0.9f);

	Texture* texture1 = new Texture("grass.png", 0);
	Texture* texture2 = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg", 1);
	Texture* texture3 = new Texture("house.png", 2);

	BasicTransformation* basicTransformation = new BasicTransformation();
	basicTransformation->addTransformationComponent(new Scale(10.0f));
	//basicTransformation->addTransformationComponent(new Rotation(glm::vec3(1.f, 1.f, 0.f), (rand() % 360)));

	skybox = new DrawableObject(modelSkyCube, constShader3);
	skybox->setTexture(texture2);

	drawableObject = new DrawableObject(modelHouse, constShader2);
	drawableObject->setTexture(texture3);
	addDrawableObject(drawableObject);

	srand((time(0)));
	for (int j = 0; j < 100; j++) {
		float randomX = (rand() % 200 - 130) / 10.0f;
		float randomY = (rand() % 200 - 130) / 10.0f;
		float randomScale = (rand() % 26 + 5) / 100.0f;

		drawableObject = new DrawableObject(modelTree, constShader);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		if (j < rotateObjectsCount) {
			transformationComponent = new DynamicRotation(0.025f, glm::vec3(0.f, 1.f, 0.f), (rand() % 360));

			drawableObject->addBasicTransformation(basicTransformation);
		}
		else {
			transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		}

		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setMaterial(material);
		addDrawableObject(drawableObject);
	}

	for (int j = 0; j < 100; j++) {
		float randomX = (rand() % 200 - 130) / 10.0f;
		float randomY = (rand() % 200 - 130) / 10.0f;
		float randomScale = (rand() % 26 + 15) / 100.0f;

		drawableObject = new DrawableObject(modelBush, constShader);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setMaterial(material2);
		addDrawableObject(drawableObject);
	}


	drawableObject = new DrawableObject(modelPlain, constShader2);
	transformationComponent = new Scale(20.0f);
	drawableObject->addTransformationComponent(transformationComponent);

	drawableObject->setMaterial(material);
	drawableObject->setTexture(texture1);
	addDrawableObject(drawableObject);

	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

}

void Scene::initScene6()
{
	int rotateObjectsCount = 5;
	shaderProgram = new ShaderProgram("vertex_shader_phong_more_lights.glsl", "fragment_shader_phong_more_lights.glsl");
	shaderProgram2 = new ShaderProgram("vertex_shader_texture_lights.glsl", "fragment_shader_texture_lights.glsl");
	constShader = new ConstShader("vertex_shader_skycube.glsl", "fragment_shader_skycube_night.glsl");

	ModelFactory* modelFactory = new ModelFactory();
	//ModelInterface* modelTree = modelFactory->create(tree, sizeof(tree), 92814);
	ModelInterface* modelBush = modelFactory->create(bushes, sizeof(bushes), 8730);

	ModelTextureFactory* modelTextureFactory = new ModelTextureFactory();
	ModelInterface* modelPlain = modelTextureFactory->create(plaintexture, sizeof(plaintexture), 6);

	ModelObjectFactory* modelObjectFactory = new ModelObjectFactory();
	ModelInterface* modelHouse = modelObjectFactory->create("house.obj");
	ModelInterface* modelZombie = modelObjectFactory->create("zombie.obj");
	ModelInterface* modelLogin = modelObjectFactory->create("login.obj");
	ModelInterface* modelTerrain = modelObjectFactory->create("teren.obj");
	ModelInterface* modelTree = modelObjectFactory->create("tree.obj");
	ModelInterface* modelBigHouse = modelObjectFactory->create("house2.obj");

	ModelSkycubeFactory* modelSkycubeFactory = new ModelSkycubeFactory();
	ModelInterface* modelSkyCube = modelSkycubeFactory->create(skycube, sizeof(skycube), 36);


	Material* material = new Material(0.075f, 0.8f, 1.0f);
	Material* material2 = new Material(0.2f, 0.6f, 0.9f);

	Texture* texture1 = new Texture("grass.png", 0);
	Texture* texture2 = new Texture("zombie.png", 1);
	Texture* texture3 = new Texture("house.png", 2);
	Texture* texture4 = new Texture("gold.jpg", 3);
	Texture* texture5 = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg", 4);
	Texture* texture6 = new Texture("tree.png", 5);
	Texture* texture7 = new Texture("house2.jpg", 6);

	DrawableObject* drawableObject;

	TransformationComponent* transformationComponent;

	skybox = new DrawableObject(modelSkyCube, constShader);
	skybox->setTexture(texture5);

	drawableObject = new DrawableObject(modelHouse, shaderProgram2);
	drawableObject->setTexture(texture3);
	transformationComponent = new Translation(glm::vec3(20.f, 0.f, 20.f));
	drawableObject->addTransformationComponent(transformationComponent);
	transformationComponent = new Scale(0.4f);
	drawableObject->addTransformationComponent(transformationComponent);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelBigHouse, shaderProgram2);
	drawableObject->setTexture(texture7);
	transformationComponent = new Translation(glm::vec3(-30.f, 0.f, -30.f));
	drawableObject->addTransformationComponent(transformationComponent);
	transformationComponent = new Scale(0.04f);
	drawableObject->addTransformationComponent(transformationComponent);
	addDrawableObject(drawableObject);

	drawableObject = new DrawableObject(modelLogin, shaderProgram2);
	drawableObject->setTexture(texture4);
	transformationComponent = new Translation(glm::vec3(8.f, 0.f, -6.f));
	drawableObject->addTransformationComponent(transformationComponent);
	addDrawableObject(drawableObject);


	drawableObject = new DrawableObject(modelTerrain, shaderProgram2);
	drawableObject->setTexture(texture1);
	transformationComponent = new Scale(2.f);
	drawableObject->addTransformationComponent(transformationComponent);
	drawableObject->setMaterial(material);
	addDrawableObject(drawableObject);

	srand((time(0)));
	for (int j = 0; j < 150; j++) {
		float randomX = (rand() % 501 - 250) / 10.0f;
		float randomY = (rand() % 501 - 250) / 10.0f;

		float randomScale = (rand() % 10 + 1) / 100.0f;

		drawableObject = new DrawableObject(modelTree, shaderProgram2);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		if (j < rotateObjectsCount) {
			transformationComponent = new DynamicRotation(0.025f, glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		}
		else {
			transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		}

		drawableObject->addTransformationComponent(transformationComponent);

		//drawableObject->setMaterial(material);
		drawableObject->setTexture(texture6);
		addDrawableObject(drawableObject);
	}

	for (int j = 0; j < 50; j++) {
		float randomX = (rand() % 501 - 250) / 10.0f;
		float randomY = (rand() % 501 - 250) / 10.0f;

		float randomScale = (rand() % 26 + 15) / 100.0f;

		drawableObject = new DrawableObject(modelBush, shaderProgram);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setMaterial(material2);
		addDrawableObject(drawableObject);
	}

	for (int j = 0; j < 20; j++) {
		float randomX = (rand() % 501 - 250) / 10.0f;
		float randomY = (rand() % 501 - 250) / 10.0f;
		float randomScale = (rand() % 40 + 20) / 100.0f;

		drawableObject = new DrawableObject(modelZombie, shaderProgram2);

		transformationComponent = new Translation(glm::vec3(randomX, 0.f, randomY));
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Scale(randomScale);
		drawableObject->addTransformationComponent(transformationComponent);

		transformationComponent = new Rotation(glm::vec3(0.f, 1.f, 0.f), (rand() % 360));
		drawableObject->addTransformationComponent(transformationComponent);

		drawableObject->setTexture(texture2);
		addDrawableObject(drawableObject);
	}


	drawableObject = new DrawableObject(modelPlain, shaderProgram2);
	transformationComponent = new Scale(20.0f);
	drawableObject->addTransformationComponent(transformationComponent);

	drawableObject->setMaterial(material);
	drawableObject->setTexture(texture1);
	//addDrawableObject(drawableObject);
}

void Scene::drawSkybox() {
	glDepthMask(GL_FALSE);
	skybox->setSkyBoxUniform(true);
	skybox->draw();
	glDepthMask(GL_TRUE);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Scene::drawCubeSkybox() {
	skybox->setSkyBoxUniform(false);
	skybox->draw();
}

void Scene::draw()
{
	for (DrawableObject* object : objects)
	{
		glStencilFunc(GL_ALWAYS, object->getId(), 0xFF);
		object->draw();
	}
}

void Scene::addDrawableObject(DrawableObject* object)
{
	objects.push_back(object);
	drawableObjectsCount++;
	object->setID(drawableObjectsCount);
}

void Scene::addTree(glm::vec3 position)
{
	Model* modelTree = new Model(tree, sizeof(tree), 92814);
	DrawableObject* drawableObject;
	if (shaderProgram)
		drawableObject = new DrawableObject(modelTree, shaderProgram);
	else
		drawableObject = new DrawableObject(modelTree, constShader);
	TransformationComponent* transformationComponent;

	transformationComponent = new Translation(position);
	drawableObject->addTransformationComponent(transformationComponent);
	transformationComponent = new Scale(0.3f);
	drawableObject->addTransformationComponent(transformationComponent);
	addDrawableObject(drawableObject);

}

void Scene::addPointToBezierCurve(glm::vec3 point)
{
	bezierCurve->addPoint(point);
}

void Scene::addBezierCurveToObject(GLuint index)
{
	DrawableObject* object = objects[index - 1];
	object->addTransformationComponent(bezierCurve);

}

void Scene::addObserver(Camera* camera)
{
	if (constShader != nullptr) {
		camera->addObserver(constShader);
		constShader->addCamera(camera);
	}
	if (constShader2 != nullptr) {
		camera->addObserver(constShader2);
		constShader2->addCamera(camera);
	}
	if (constShader3 != nullptr) {
		camera->addObserver(constShader3);
		constShader3->addCamera(camera);
	}
	if (shaderProgram != nullptr) {
		camera->addObserver(shaderProgram);
		shaderProgram->addCamera(camera);
	}
	if (shaderProgram2 != nullptr) {
		camera->addObserver(shaderProgram2);
		shaderProgram2->addCamera(camera);
	}
	if (shaderProgram3 != nullptr) {
		camera->addObserver(shaderProgram3);
		shaderProgram3->addCamera(camera);
	}
	if (shaderProgram4 != nullptr) {
		camera->addObserver(shaderProgram4);
		shaderProgram4->addCamera(camera);
	}
}

void Scene::addObserver(Light* light)
{
	if (shaderProgram != nullptr) {
		light->addObserver(shaderProgram);
		shaderProgram->addLight(light);
	}
	if (shaderProgram2 != nullptr) {
		light->addObserver(shaderProgram2);
		shaderProgram2->addLight(light);
	}
	if (shaderProgram3 != nullptr) {
		light->addObserver(shaderProgram3);
		shaderProgram3->addLight(light);
	}
	if (shaderProgram4 != nullptr) {
		light->addObserver(shaderProgram4);
		shaderProgram4->addLight(light);
	}

}


