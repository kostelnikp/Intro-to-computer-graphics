#version 330 core

layout(location = 0) in vec3 vp;

out vec3 normal;

void main() {
    gl_Position = vec4(vp, 1.0);
}
