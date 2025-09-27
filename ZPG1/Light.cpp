#include "Light.h"

Light::Light() {
	color = glm::vec3(1.0f, 1.0f, 1.0f);
}



glm::vec3 Light::getColor() const {
    return color;
}

int Light::getType() const
{
    return type;
}

void Light::addObserver(ObserverInterface* observer) {
    observers.push_back(observer);
}

void Light::notifyObservers() {
    for (ObserverInterface* observer : observers) {
		observer->update(3);                            // 3 - Light - color
    }
}

void Light::setColor(const glm::vec3& newColor) {
    color = newColor;
    notifyObservers();
}

