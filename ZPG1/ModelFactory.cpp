#include "ModelFactory.h"

ModelInterface* ModelFactory::create(const float* points, int vertexCount, int numberOfPoints)
{
	return new Model(points, vertexCount, numberOfPoints);
}

ModelInterface* ModelFactory::create(const char* path)
{
    return nullptr;
}
