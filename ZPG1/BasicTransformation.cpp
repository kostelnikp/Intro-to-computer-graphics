#include "BasicTransformation.h"

BasicTransformation::BasicTransformation()
{
}

void BasicTransformation::addTransformationComponent(TransformationComponent* component)
{
	components.push_back(component);
}

TransformationComponent* BasicTransformation::getTransformation(int index)
{
	return components[index];
}

int BasicTransformation::getComponentsCount()
{
	return components.size();
}
