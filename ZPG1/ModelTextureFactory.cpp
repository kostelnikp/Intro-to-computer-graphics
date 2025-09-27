#include "ModelTextureFactory.h"

ModelInterface* ModelTextureFactory::create(const float* points, int vertexCount, int numberOfPoints)
{
	return new ModelTexture(points, vertexCount, numberOfPoints);
}

ModelInterface* ModelTextureFactory::create(const char* path)
{
    return nullptr;
}
