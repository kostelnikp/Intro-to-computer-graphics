#include "ModelObject.h"

ModelObject::ModelObject(const char* path) : ModelInterface()
{
	ModelData modelData = load(path);
	VAO = modelData.VAO;
	vertexCount = modelData.indicesCount;
}


void ModelObject::draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
