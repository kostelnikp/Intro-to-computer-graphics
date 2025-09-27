#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Shader
{
private:
	GLuint shaderID;

public:
	Shader(const char* shaderSource, GLenum shaderType);
	GLuint getShaderID();

};

