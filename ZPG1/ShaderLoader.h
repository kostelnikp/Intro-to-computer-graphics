#pragma once
//GLEW - The OpenGL Extension Wrangler Library
#include <GL/glew.h>

#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */

using namespace std;

class ShaderLoader
{
	GLuint vertexID = 0;
	GLuint fragmentID = 0;
	string loadFile(const char* fname);
protected:
	GLuint	shaderProgramID = 0;
public:
	GLuint loadShader(const char* vertexFile, const char* fragmentFile);
	void deleteShader();
	ShaderLoader();
	ShaderLoader(const char* vertexFile, const char* fragmentFile, GLuint* shaderID);
	~ShaderLoader();
};
