#pragma once

#include "ModelObjectLoader.h"
#include "ModelInterface.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelObject : public ModelObjectLoader, public ModelInterface
{
public:
	ModelObject(const char* path);
	void draw();

};

