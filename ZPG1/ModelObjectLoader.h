#pragma once

#include <GL/glew.h>
#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtx/string_cast.hpp>

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */



struct ModelData
{
	GLuint VAO;
	int indicesCount;
};

class ModelObjectLoader
{
private:
	ModelData modelData;

	struct Vertex
	{
		float Position[3];
		float Normal[3];
		float Texture[2];
		float Tangent[3];
	};

public:


	ModelObjectLoader();
	ModelData load(const char* fileName);
};

