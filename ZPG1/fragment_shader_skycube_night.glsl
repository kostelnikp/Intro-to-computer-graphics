#version 330

in vec3 fragmentLocalPosition;

uniform samplerCube textureUnitID;
uniform vec3 viewPosition;

out vec4 frag_colour;

void main () {
    vec4 color = texture(textureUnitID, fragmentLocalPosition);
    
    frag_colour = color * 0.25;
}
