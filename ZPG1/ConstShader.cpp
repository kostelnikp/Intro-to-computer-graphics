#include "ConstShader.h"

void ConstShader::update(int updateType)
{
	if (updateType == 0) {													// 0 - Camera - view matrix
		glm::mat4 viewMatrix = camera->getViewMatrix();
		updateViewMatrix(viewMatrix);
	}
	else if (updateType == 1) { 											// 1 - Camera - projection matrix
		glm::mat4 projectionMatrix = camera->getProjectionMatrix();
		updateProjectionMatrix(projectionMatrix);
	}
}
