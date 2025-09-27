#include "ModelSkycubeFactory.h"

ModelInterface* ModelSkycubeFactory::create(const float* points, int vertexCount, int numberOfPoints)
{
	return new ModelSkycube(points, vertexCount, numberOfPoints);
}

ModelInterface* ModelSkycubeFactory::create(const char* path)
{
	return nullptr;
}
