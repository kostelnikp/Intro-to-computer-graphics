#pragma once

#include "ModelObjectLoader.h"
#include "ModelInterface.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelObject : public ModelObjectLoader, public ModelInterface
{
public:
	ModelObject(const char* path);
	void draw();

};

