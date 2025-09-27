#pragma once

#include "ModelInterface.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class FactoryInterface
{
public:
	virtual ModelInterface* create(const float* points, int vertexCount, int numberOfPoints) = 0;
	virtual ModelInterface* create(const char* path) = 0;
};

