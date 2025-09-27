#include "Transformation.h"

Transformation::Transformation()
{
	modelMatrix = glm::mat4(1.0f);
}

void Transformation::addTransformationComponent(TransformationComponent* component)
{
	components.push_back(component);
}

void Transformation::addBasicTransformation(BasicTransformation* basicTransformation)
{
	for (int i = 0; i < basicTransformation->getComponentsCount(); i++)
	{
		TransformationComponent* component = basicTransformation->getTransformation(i);
		this->components.push_back(component);
	}
}

//TransformationComponent* Transformation::getTransformation(int index)
//{
//	return components[index];
//}

//void Transformation::updateTransformation(int index, TransformationComponent* component)
//{
//	components[index] = component;
//}



glm::mat4 Transformation::getModelMatrix()
{
	modelMatrix = glm::mat4(1.0f);

	for (TransformationComponent* component : components)
	{
		modelMatrix = modelMatrix * component->getComponentMatrix();
	}

	return modelMatrix;
}

//int Transformation::getComponentsCount()
//{
//	return components.size();
//}
