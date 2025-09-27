#pragma once
#include "SubjectInterface.h"
#include "ObserverInterface.h"
#include <glm/glm.hpp>
#include <vector>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


typedef struct {
    float constant;
    float linear;
    float quadratic;
} Attenuation;

class Light : public SubjectInterface {
protected:
    glm::vec3 color;
	int type;               // 1 - point light, 2 - spot light, 3 - directional light

public:
    Light();

    void setColor(const glm::vec3& newColor);

    glm::vec3 getColor() const;
	int getType() const;

    void addObserver(ObserverInterface* observer);
    void notifyObservers() override;
};
