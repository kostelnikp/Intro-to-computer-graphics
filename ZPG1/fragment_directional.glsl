#version 330 core

in vec3 fragPosition;
in vec3 normal;

out vec4 fragColor;

uniform vec3 lightColor;        
uniform vec3 lightDirection;  
uniform vec3 viewPosition;    

void main()
{
    vec4 objectColor = vec4(0.385, 0.647, 0.812, 1.0);

   
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(-lightDirection);

  
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

 
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPosition - fragPosition); 
    vec3 reflectDir = reflect(-lightDir, norm);           
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); 
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor.rgb;
    fragColor = vec4(result, 1.0);
}
