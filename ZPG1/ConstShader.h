#pragma once

#include "ShaderProgram.h"

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */



class ConstShader : public ShaderProgram
{
public:
	ConstShader(const char* vertexFile, const char* fragmentFile) : ShaderProgram(vertexFile, fragmentFile) {}
	void update(int updateType);
};

