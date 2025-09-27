#include "ModelObjectFactory.h"

ModelInterface* ModelObjectFactory::create(const float* points, int vertexCount, int numberOfPoints)
{
    return nullptr;
}

ModelInterface* ModelObjectFactory::create(const char* path)
{
	return new ModelObject(path);
}
