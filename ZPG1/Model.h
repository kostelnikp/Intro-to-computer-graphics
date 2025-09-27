#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include "ModelInterface.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Model : public ModelInterface
{
public:
	Model(const float* points, int vertexCount, int numberOfPoints);
	void draw();

};

