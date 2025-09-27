#pragma once

#include <glm/glm.hpp>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class ObserverInterface
{
public:
	// 0 - Camera - view matrix
	// 1 - Camera - projection matrix
	// 2 - Light - position
	// 3 - Light - color
	// 4 - Light - attenuation
	// 5 - Light - cutOff
	// 6 - Light - direction
	// 7 - Camera - view direction
	// 8 - Camera - position


	virtual void update(int updateType) = 0;
};
