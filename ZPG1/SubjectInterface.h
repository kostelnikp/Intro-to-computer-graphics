#pragma once

#include "ObserverInterface.h"
#include <vector>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class SubjectInterface
{
protected:
	std::vector<ObserverInterface*> observers;

public:
	virtual void addObserver(ObserverInterface* observer) = 0;
	virtual void notifyObservers() = 0;
};