#version 330 core

in vec3 normal;
out vec4 frag_colour;

uniform vec3 viewPosition;

void main() {
    frag_colour = vec4(normal, 1.0);
}
