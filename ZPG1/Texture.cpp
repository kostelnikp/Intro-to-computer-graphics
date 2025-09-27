#include "Texture.h"

Texture::Texture(const char* textureSource, int textureUnit)
{
	this->textureUnit = textureUnit;
	glActiveTexture(GL_TEXTURE0 + this->textureUnit);

	this->textureID = SOIL_load_OGL_texture(textureSource, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	
	if (this->textureID == NULL) {
		std::cout << "An error occurred while loading texture " << textureSource << std::endl;
		exit(EXIT_FAILURE);
	}

	glBindTexture(GL_TEXTURE_2D, this->textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unbind();
}

Texture::Texture(const char* posX, const char* negX, const char* posY, const char* negY, const char* posZ, const char* negZ, int textureUnit)
{
	this->textureUnit = textureUnit;
	glActiveTexture(GL_TEXTURE0 + this->textureUnit);

	this->textureID = SOIL_load_OGL_cubemap(posX, negX, posY, negY, posZ, negZ, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	if (this->textureID == NULL) {
		std::cout << "An error occurred while loading cubemap" << std::endl;
		exit(EXIT_FAILURE);
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unbind();

}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + this->textureUnit);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::getTextureUnit()
{
	return textureUnit;
}

GLuint Texture::getTextureID()
{
	return textureID;
}
