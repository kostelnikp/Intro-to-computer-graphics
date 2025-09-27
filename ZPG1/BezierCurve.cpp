#include "BezierCurve.h"

BezierCurve::BezierCurve()
{
    A = glm::mat4(
        glm::vec4(-1.0, 3.0, -3.0, 1.0),
        glm::vec4(3.0, -6.0, 3.0, 0),
        glm::vec4(-3.0, 3.0, 0, 0),
        glm::vec4(1.0, 0.0, 0.0, 0.0)
    );

	p = glm::vec3(0.0, 0.0, 0.0);
    t = 0.5f;
	delta = 0.01f;
}

void BezierCurve::addPoint(glm::vec3 point)
{
	bezierPoints.push_back(point);
}

void BezierCurve::calculateCurve()
{
    glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
	glm::mat4x3 B = glm::mat4x3(
		bezierPoints[0],
		bezierPoints[1],
		bezierPoints[2],
		bezierPoints[3]
	);
    p = parameters * A * glm::transpose(B);

	if (t >= 1.0f || t <= 0.0f) delta *= -1;
	t += delta;
}

glm::mat4 BezierCurve::getComponentMatrix()
{
	if (bezierPoints.size() < 4) return glm::mat4(1.0f);
	else {
		calculateCurve();
		return glm::translate(glm::mat4(1.0f), p);
	}
}
