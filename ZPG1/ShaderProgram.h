#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "ObserverInterface.h"
#include "Light.h"
#include "ShaderLoader.h"
#include "SubjectInterface.h"
#include "Camera.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionalLight.h"
#include "Material.h"
#include "Texture.h"

/*
 * Autor: Peter Kostelník
 * Login: KOS0378
 * Dátum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Camera;
class ShaderProgram : public ObserverInterface, ShaderLoader
{
private:
	vector<Light*> lights;
	int numberOfLights;

protected:
	GLuint programID;
	Camera* camera;

public:
	ShaderProgram(const char* vertexSource, const char* fragmentSource);

	void setShader();
	void unbindShader();

	void addCamera(Camera* camera);
	void addLight(Light* light);

	void updateModelMatrix(glm::mat4& matrix);
	void updateViewMatrix(glm::mat4& matrix);
	void updateViewPosition(glm::vec3& position);
	void updateProjectionMatrix(glm::mat4& matrix);
	void updateLightPosition(int posInVector, glm::vec3& position);
	void updateLightColor(int posInVector, glm::vec3& color);
	void updateLightAttenuation(int posInVector, Attenuation attenuation);
	void updateLightCutOff(int posInVector, float cutOff);
	void updateLightDirection(int posInVector, glm::vec3& direction);
	void updateLightType(int posInVector, int type);
	void updateLightCount();
	void updateMaterial(Material* material);
	void updateTexture(Texture* texture);
	void updateSkyBox(bool isSkyBox);

	void update(int updateType) override;

	void setUniform4fv(const char* name, glm::mat4& matrix);
	void setUniform3fv(const char* name, glm::vec3& vector);
	void setUniform1fv(const char* name, float value);
	void setUniform1i(const char* name, int value);

};

