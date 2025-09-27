#include "ModelSkycube.h"

ModelSkycube::ModelSkycube(const float* points, int vertexCount, int numberOfPoints) : ModelInterface(points, vertexCount)
{
	GLuint VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount, points, GL_STATIC_DRAW);

	VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);

	this->vertexCount = numberOfPoints;
}

void ModelSkycube::draw()
{
	setModel();
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
