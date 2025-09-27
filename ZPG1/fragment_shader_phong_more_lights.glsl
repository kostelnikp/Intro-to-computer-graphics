#version 330 core

#define MAX_LIGHTS 5

in vec3 fragPosition;
in vec3 normal;

out vec4 frag_colour;

uniform vec3 viewPosition;

struct Light {
    int lightType;         // 1 = Point Light, 2 = Spot Light, 3 = Directional Light
    vec3 lightPosition;   
    vec3 lightColor;       
    vec3 attenuation;      
    float cutOff;          
    vec3 lightDirection;  
};

uniform int numberOfLights;
uniform Light lights[MAX_LIGHTS];

uniform float ra; 
uniform float rd; 
uniform float rs; 

void main()
{
    float shininess = 32.0; 
    vec4 objectColor = vec4(0.385, 0.647, 0.812, 1.0); 
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPosition - fragPosition);
    vec3 resultColor = vec3(0.0);

    vec3 ambient = ra * vec3(1.0, 1.0, 1.0);

    for (int i = 0; i < numberOfLights; i++) {
        vec3 lightDir;
        float attenuation = 1.0;

        if (lights[i].lightType == 1) {
            lightDir = normalize(lights[i].lightPosition - fragPosition);
            float distance = length(lights[i].lightPosition - fragPosition);

            float constant = lights[i].attenuation.x;
            float linear = lights[i].attenuation.y;
            float quadratic = lights[i].attenuation.z;
            attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));
        }
        else if (lights[i].lightType == 2) {
            lightDir = normalize(lights[i].lightPosition - fragPosition);
            float spot = dot(normalize(lights[i].lightDirection), -lightDir);

            if (spot < lights[i].cutOff) {
                continue; 
            }

            spot = (spot - lights[i].cutOff) / (1.0 - lights[i].cutOff);

            float distance = length(lights[i].lightPosition - fragPosition);
            float constant = lights[i].attenuation.x;
            float linear = lights[i].attenuation.y;
            float quadratic = lights[i].attenuation.z;
            attenuation = spot * (1.0 / (constant + linear * distance + quadratic * (distance * distance)));
        }
        else if (lights[i].lightType == 3) {
            lightDir = normalize(-lights[i].lightDirection);
            attenuation = 1.0; 
        }

        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = rd * diff * lights[i].lightColor * attenuation;

        vec3 reflectVector = normalize(reflect(-lightDir, norm));
        float spec = pow(max(dot(viewDir, reflectVector), 0.0), shininess);
        vec3 specular = rs * spec * lights[i].lightColor * attenuation;

        resultColor += diffuse + specular;
    }

    frag_colour = vec4(ambient + resultColor, objectColor.a);
}
