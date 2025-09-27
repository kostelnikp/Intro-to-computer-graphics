#version 330 core

in vec3 worldNormal;
uniform vec3 lightDirection;
uniform vec3 lightPosition;
in vec3 worldPosition;

void main() {
    vec3 camVector = normalize(vec3(5, 5, 0) - worldPosition);
    vec3 lightVector = normalize(lightPosition - worldPosition);
    vec3 reflectVector = normalize(reflect(-lightVector, normalize(worldNormal)));
    float diff = max(dot(normalize(lightVector), normalize(worldNormal)), 0.0);
    float spec = pow(max(dot(reflectVector, camVector), 0.0), 32);
    float spot = dot(normalize(lightDirection), -lightVector);
    if (spot < 0.99) {
        spec = 0;
        diff = 0;
    }
    spot = (spot - 0.99) / (1 - 0.99);
    gl_FragColor = (0.01 + (diff + spec) * spot) * vec4(0.385, 0.647, 0.812, 1.0);
}
