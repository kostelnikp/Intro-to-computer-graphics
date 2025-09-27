#pragma once

#include "TransformationComponent.h"
#include "BasicTransformation.h"
#include "ShaderProgram.h"
#include <vector>

class Transformation
{
private:
	glm::mat4 modelMatrix;

protected:
	std::vector<TransformationComponent*> components;


public:
	Transformation();

	void addTransformationComponent(TransformationComponent* component);
	void addBasicTransformation(BasicTransformation* basicTransformation);
	//TransformationComponent* getTransformation(int index);
	//void updateTransformation(int index, TransformationComponent* component);
	glm::mat4 getModelMatrix();

	//int getComponentsCount();
};

