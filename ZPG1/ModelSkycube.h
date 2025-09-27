#pragma once

#include "ModelInterface.h"
#include "ModelObjectLoader.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelSkycube : public ModelInterface
{
public:
	ModelSkycube(const float* points, int vertexCount, int numberOfPoints);
	void draw();
};

