#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include "ModelInterface.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Model : public ModelInterface
{
public:
	Model(const float* points, int vertexCount, int numberOfPoints);
	void draw();

};

