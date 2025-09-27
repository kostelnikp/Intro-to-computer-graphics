#version 330
layout(location = 0) in vec3 vp;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform int isSkyBox;

out vec3 fragmentLocalPosition;

void main() {
    if (isSkyBox == 1) {
        mat4 viewMatrixWithoutTranslation = mat4(mat3(viewMatrix));
    gl_Position = projectionMatrix * viewMatrixWithoutTranslation * vec4(vp, 1.0);
    } else {
        gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);
    }
    fragmentLocalPosition = vp;
}
