#pragma once

#include "FactoryInterface.h"
#include "ModelTexture.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ModelTextureFactory : public FactoryInterface {
public:
    ModelInterface* create(const float* points, int vertexCount, int numberOfPoints) override;

    ModelInterface* create(const char* path) override;
};
