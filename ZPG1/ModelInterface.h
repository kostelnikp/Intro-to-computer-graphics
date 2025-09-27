#pragma once

#include <GL/glew.h>
#include <stdlib.h>

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelInterface
{
protected:
	GLuint VAO;
	int vertexCount;

public:
	ModelInterface() {};
	ModelInterface(const float* points, int vertexCount) {};
	void setModel();
	virtual void draw() = 0;

};

