#include "Model.h"

Model::Model(const float* points, int vertexCount, int numberOfPoints) : ModelInterface(points, vertexCount)
{
	GLuint VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount, points, GL_STATIC_DRAW);

	VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

	this->vertexCount = numberOfPoints;
	glBindVertexArray(0);
}

void Model::draw()
{
	setModel();
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
