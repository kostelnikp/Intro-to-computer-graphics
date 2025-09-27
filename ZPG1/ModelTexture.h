#pragma once

#include "ModelInterface.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelTexture : public ModelInterface
{
public:
	ModelTexture(const float* points, int vertexCount, int numberOfPoints);
	void draw();
};

