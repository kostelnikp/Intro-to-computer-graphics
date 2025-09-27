#pragma once

#include <GL/glew.h>
#include <SOIL.h>
#include <iostream>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Texture
{
private:
	GLuint textureID;
	int textureUnit;
public:
	Texture(const char* textureSource, int textureUnit);
	Texture(const char* posX, const char* negX, const char* posY, const char* negY, const char* posZ, const char* negZ, int textureUnit);

	void bind();
	void unbind();

	int getTextureUnit();
	GLuint getTextureID();


};

