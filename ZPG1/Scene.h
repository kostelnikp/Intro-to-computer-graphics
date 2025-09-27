#pragma once

#include "ShaderProgram.h"
#include "ConstShader.h"
#include "DrawableObject.h"
#include "Sphere.h"
#include "Tree.h"
#include "Bushes.h"
#include "SuziFlat.h"
#include "Plain.h"
#include "Scale.h"
#include "Translation.h"
#include "Rotation.h"
#include "Camera.h"
#include "Light.h"
#include "DynamicRotation.h"
#include "Material.h"
#include "Texture.h"
#include "ModelTexture.h"
#include "PlainTexture.h"
#include "SkyCube.h"
#include "ModelSkycube.h"
#include "ModelInterface.h"
#include "Model.h"
#include <random>
#include <ctime>
#include <vector>
#include "ModelObject.h"
#include "Transformation.h"
#include "BezierCurve.h"
#include "ModelFactory.h"
#include "ModelTextureFactory.h"
#include "ModelSkycubeFactory.h"
#include "ModelObjectFactory.h"
#include "BasicTransformation.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */



class Scene
{
private:
	std::vector<DrawableObject*> objects;
	std::vector<DrawableObject*> rotateObjects;

	ConstShader* constShader;
	ConstShader* constShader2;
	ConstShader* constShader3;
	ShaderProgram* shaderProgram;
	ShaderProgram* shaderProgram2;
	ShaderProgram* shaderProgram3;
	ShaderProgram* shaderProgram4;
	Camera* camera;
	DrawableObject* skybox;
	BezierCurve* bezierCurve;

	int drawableObjectsCount;

public:
	Scene();
	void initScene1();
	void initScene2();
	void initScene3();
	void initScene4();
	void initScene5();
	void initScene6();

	void draw();
	void drawSkybox();
	void drawCubeSkybox();
	void addDrawableObject(DrawableObject* object);
	void addTree(glm::vec3 position);
	void addPointToBezierCurve(glm::vec3 point);
	void addBezierCurveToObject(GLuint index);
	void addObserver(Camera* camera);
	void addObserver(Light* light);

};

