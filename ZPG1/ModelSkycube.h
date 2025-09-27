#pragma once

#include "ModelInterface.h"
#include "ModelObjectLoader.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelSkycube : public ModelInterface
{
public:
	ModelSkycube(const float* points, int vertexCount, int numberOfPoints);
	void draw();
};

