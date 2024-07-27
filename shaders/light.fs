#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform vec3 viewPos;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);

    // NOTE: Implement here your fragment shader code

    vec3 ambientLight = vec3(0.5, 0.5, 0.5);

    vec3 viewDirection = normalize(viewPos);

    //diffuse lambertian
    vec3 normal = normalize(fragNormal);
    vec3 lightColor = vec3(1.0,1.0,1.0);
    vec3 lightPos = vec3(1.0,0.0,0.0);
    float diffuseVal = max(0.0, dot(normal,normalize(lightPos)));
    vec3 diffuse = diffuseVal * lightColor;


    //Specular
    vec3 reflectSource = normalize(reflect(-lightPos, normal));
    float specStrength = max(0.0, dot(viewDirection, reflectSource));
    specStrength = pow(specStrength, 64);
    vec3 spec = specStrength * lightColor;


    vec3 shading = spec  + diffuse * 0.5 + ambientLight * 0.6 ;
    finalColor = vec4(texelColor.rgb * shading, 1.0);
}
