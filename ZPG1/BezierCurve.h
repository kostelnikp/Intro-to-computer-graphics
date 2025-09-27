#pragma once

#include <glm/glm.hpp>
#include "TransformationComponent.h"
#include <vector>


class BezierCurve : public TransformationComponent
{
private:
	std::vector<glm::vec3> bezierPoints;
	glm::mat4 A;
	glm::vec3 p;
	float t;
	float delta;

public:
	BezierCurve();
	void addPoint(glm::vec3 point);

	void calculateCurve();
	
	glm::mat4 getComponentMatrix() override;

};

