#pragma once

#include "ModelInterface.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelTexture : public ModelInterface
{
public:
	ModelTexture(const float* points, int vertexCount, int numberOfPoints);
	void draw();
};

