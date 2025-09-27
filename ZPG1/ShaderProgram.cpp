#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const char* vertexFile, const char* fragmentFile) {
	programID = loadShader(vertexFile, fragmentFile);
	if (programID == 0) {
		std::cerr << "Failed to load shaders." << std::endl;
	}
	camera = nullptr;
	numberOfLights = 0;
}

void ShaderProgram::setShader()
{
	glUseProgram(programID);
}

void ShaderProgram::unbindShader()
{
	glUseProgram(0);
}

void ShaderProgram::addCamera(Camera* camera)
{
	this->camera = camera;
}

void ShaderProgram::addLight(Light* light)
{
	lights.push_back(light);
	numberOfLights = lights.size();
	updateLightType(numberOfLights - 1, light->getType());
	updateLightCount();
}

void ShaderProgram::updateModelMatrix(glm::mat4& matrix)
{
	setUniform4fv("modelMatrix", matrix);
}

void ShaderProgram::updateViewMatrix(glm::mat4& matrix)
{
	setUniform4fv("viewMatrix", matrix);
}

void ShaderProgram::updateViewPosition(glm::vec3& position)
{
	setUniform3fv("viewPosition", position);
}

void ShaderProgram::updateProjectionMatrix(glm::mat4& matrix)
{
	setUniform4fv("projectionMatrix", matrix);
}

void ShaderProgram::updateLightPosition(int posInVector, glm::vec3& position)
{
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].lightPosition";
	setUniform3fv(uniformName.c_str(), position);
}

void ShaderProgram::updateLightColor(int posInVector, glm::vec3& color)
{
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].lightColor";
	setUniform3fv(uniformName.c_str(), color);
}

void ShaderProgram::updateLightAttenuation(int posInVector, Attenuation attenuation)
{
	glm::vec3 attenuationVector = glm::vec3(attenuation.constant, attenuation.linear, attenuation.quadratic);
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].attenuation";
	setUniform3fv(uniformName.c_str(), attenuationVector);
}

void ShaderProgram::updateLightCutOff(int posInVector, float cutOff)
{
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].cutOff";
	setUniform1fv(uniformName.c_str(), cutOff);
}

void ShaderProgram::updateLightDirection(int posInVector, glm::vec3& direction)
{
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].lightDirection";
	setUniform3fv(uniformName.c_str(), direction);
}

void ShaderProgram::updateLightType(int posInVector, int type)
{
	std::string uniformName = "lights[" + std::to_string(posInVector) + "].lightType";
	setUniform1i(uniformName.c_str(), type);
}

void ShaderProgram::updateLightCount()
{
	setUniform1i("numberOfLights", numberOfLights);
}

void ShaderProgram::updateMaterial(Material* material)
{
	setUniform1fv("ra", material->getRa());
	setUniform1fv("rd", material->getRd());
	setUniform1fv("rs", material->getRs());
}

void ShaderProgram::updateTexture(Texture* texture)
{
	texture->bind();
	setUniform1i("textureUnitID", texture->getTextureUnit());
}

void ShaderProgram::updateSkyBox(bool isSkyBox)
{
	if (isSkyBox)
	{
		setUniform1i("isSkyBox", 1);
	}
	else
	{
		setUniform1i("isSkyBox", 0);
	}
}

void ShaderProgram::setUniform4fv(const char* name, glm::mat4& matrix)
{
	this->setShader();
	GLint location = glGetUniformLocation(programID, name);
	if (location == -1)
	{
		//fprintf(stderr, "Warning: uniform '%s' not found in shader program\n", name);
	}
	else
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}

void ShaderProgram::setUniform3fv(const char* name, glm::vec3& vector) {
	this->setShader();

	GLint location = glGetUniformLocation(programID, name);
	if (location == -1) {
		//fprintf(stderr, "Warning: uniform '%s' not found in shader program\n", name);
	}
	else {
		glUniform3fv(location, 1, glm::value_ptr(vector));
	}
}

void ShaderProgram::setUniform1fv(const char* name, float value)
{
	this->setShader();

	GLint location = glGetUniformLocation(programID, name);
	if (location == -1) {
		//fprintf(stderr, "Warning: uniform '%s' not found in shader program\n", name);
	}
	else {
		glUniform1fv(location, 1, &value);
	}
}

void ShaderProgram::setUniform1i(const char* name, int value)
{
	this->setShader();

	GLint location = glGetUniformLocation(programID, name);
	if (location == -1) {
		fprintf(stderr, "Warning: uniform '%s' not found in shader program\n", name);
	}
	else {
		glUniform1i(location, value);
	}
}


void ShaderProgram::update(int updateType)
{
	if (updateType == 0) {													// 0 - Camera - view matrix
		glm::mat4 viewMatrix = camera->getViewMatrix();
		updateViewMatrix(viewMatrix);
		glm::vec3 viewPosition = camera->getPosition();
		updateViewPosition(viewPosition);
	}
	else if (updateType == 1) { 											// 1 - Camera - projection matrix
		glm::mat4 projectionMatrix = camera->getProjectionMatrix();
		updateProjectionMatrix(projectionMatrix);
	}
	else if (updateType == 2) {												// 2 - Light - position
		for (int i = 0; i < lights.size(); i++) {
			Light* light = lights[i];
			if (PointLight* pointLight = dynamic_cast<PointLight*>(light)) {
				glm::vec3 lightPosition = pointLight->getPosition();
				updateLightPosition(i, lightPosition);
			}
			else if (SpotLight* spotLight = dynamic_cast<SpotLight*>(light)) {
				glm::vec3 lightPosition = spotLight->getPosition();
				updateLightPosition(i, lightPosition);
			}
		}
	}
	else if (updateType == 3) {												// 3 - Light - color
		for (int i = 0; i < lights.size(); i++) {
			Light* light = lights[i];

			if (PointLight* pointLight = dynamic_cast<PointLight*>(light))
			{
				glm::vec3 lightColor = pointLight->getColor();
				updateLightColor(i, lightColor);
			}
			else if (SpotLight* spotLight = dynamic_cast<SpotLight*>(light)) {
				glm::vec3 lightColor = spotLight->getColor();
				updateLightColor(i, lightColor);
			}
			else if (DirectionalLight* directionalLight = dynamic_cast<DirectionalLight*>(light)) {
				glm::vec3 lightColor = directionalLight->getColor();
				updateLightColor(i, lightColor);
			}

		}
	}
	else if (updateType == 4) {												// 4 - Light - attenuation
		for (int i = 0; i < lights.size(); i++) {
			Light* light = lights[i];

			if (PointLight* pointLight = dynamic_cast<PointLight*>(light)) {
				Attenuation attenuation = pointLight->getAttenuation();
				updateLightAttenuation(i, attenuation);
			}
			else if (SpotLight* spotLight = dynamic_cast<SpotLight*>(light)) {
				Attenuation attenuation = spotLight->getAttenuation();
				updateLightAttenuation(i, attenuation);
			}
		}
	}
	else if (updateType == 5) {												// 5 - Light - cutOff
		for (int i = 0; i < lights.size(); i++) {
			Light* light = lights[i];

			if (SpotLight* spotLight = dynamic_cast<SpotLight*>(light)) {
				float cutOff = spotLight->getCutOff();
				updateLightCutOff(i, cutOff);
			}
		}
	}
	else if (updateType == 6) {												// 6 - Light - direction
		for (int i = 0; i < lights.size(); i++) {
			Light* light = lights[i];

			if (SpotLight* spotLight = dynamic_cast<SpotLight*>(light)) {
				glm::vec3 direction = spotLight->getDirection();
				updateLightDirection(i, direction);
			}
			else if (DirectionalLight* directionalLight = dynamic_cast<DirectionalLight*>(light)) {
				glm::vec3 direction = directionalLight->getDirection();
				updateLightDirection(i, direction);
			}
		}
	}
}
