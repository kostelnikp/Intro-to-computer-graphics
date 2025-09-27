#version 330 core

out vec4 frag_colour;

uniform vec3 viewPosition;

void main() {
    frag_colour = vec4(1.0, 0.5, 0.0, 1.0);
}
