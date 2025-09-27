#pragma once

#include "ModelInterface.h"
#include "Transformation.h"
#include "BasicTransformation.h"
#include "ShaderProgram.h"
#include "Rotation.h"
#include "DynamicRotation.h"
#include "Material.h"
#include "Texture.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class DrawableObject
{
private:
	ModelInterface* model;
	Transformation* transformation;
	ShaderProgram* shaderProgram;
	Material* material;
	Texture* texture;
	double lastUpdateTime = 0.0;
	int id;

public:
	DrawableObject(ModelInterface* model, ShaderProgram* shaderProgram);
	void draw();
	void addTransformationComponent(TransformationComponent* component);
	void addBasicTransformation(BasicTransformation* basicTransformation);
	void applyTransformation();
	void applyMaterial();
	void applyTexture();
	void setTexture(Texture* texture);
	void setMaterial(Material* material);
	void setSkyBoxUniform(bool isSkyBox);
	glm::mat4 getModelMatrix();

	void setID(int id);
	int getId();

};

