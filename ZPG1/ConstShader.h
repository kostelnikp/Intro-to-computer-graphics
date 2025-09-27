#pragma once

#include "ShaderProgram.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */



class ConstShader : public ShaderProgram
{
public:
	ConstShader(const char* vertexFile, const char* fragmentFile) : ShaderProgram(vertexFile, fragmentFile) {}
	void update(int updateType);
};

