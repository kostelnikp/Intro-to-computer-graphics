#pragma once

#include "TransformationComponent.h"
#include <vector>

class BasicTransformation
{
private:
	std::vector<TransformationComponent*> components;
public:
	BasicTransformation();
	void addTransformationComponent(TransformationComponent* component);
	TransformationComponent* getTransformation(int index);
	int getComponentsCount();


};

