#include "DrawableObject.h"

DrawableObject::DrawableObject(ModelInterface* model, ShaderProgram* shaderProgram)
{
	this->model = model;
	this->shaderProgram = shaderProgram;
	this->transformation = new Transformation();
	this->material = nullptr;
	this->texture = nullptr;
	this->id = -1;
}

void DrawableObject::draw()
{
	model->setModel();

	applyTransformation();
	applyMaterial();
	applyTexture();

	model->draw();
    shaderProgram->unbindShader();
}



void DrawableObject::addTransformationComponent(TransformationComponent* component)
{
	transformation->addTransformationComponent(component);
}

void DrawableObject::addBasicTransformation(BasicTransformation* basicTransformation)
{
	transformation->addBasicTransformation(basicTransformation);
}

void DrawableObject::applyTransformation()
{
	glm::mat4 modelMatrix = transformation->getModelMatrix();
	shaderProgram->updateModelMatrix(modelMatrix);
}

void DrawableObject::applyMaterial()
{
	if (material != nullptr)
		shaderProgram->updateMaterial(material);
}

void DrawableObject::applyTexture()
{
	if (texture != nullptr)
		shaderProgram->updateTexture(texture);
}

void DrawableObject::setTexture(Texture* texture)
{
	this->texture = texture;
}

void DrawableObject::setMaterial(Material* material)
{
	this->material = material;
}

void DrawableObject::setSkyBoxUniform(bool isSkyBox)
{
	shaderProgram->updateSkyBox(isSkyBox);
}

glm::mat4 DrawableObject::getModelMatrix()
{
	return transformation->getModelMatrix();
}

void DrawableObject::setID(int id)
{
	this->id = id;
}

int DrawableObject::getId()
{
	return id;
}

