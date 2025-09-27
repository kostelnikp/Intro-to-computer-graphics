#version 330 core

layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 vn;
layout(location = 2) in vec2 vt;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec2 vt_out;
out vec3 fragPosition;
out vec3 normal;

void main() {
    mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));
    normal = normalize(normalMatrix * vn);

    fragPosition = vec3(modelMatrix * vec4(vp, 1.0));
    vt_out = vt;

    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);
}
