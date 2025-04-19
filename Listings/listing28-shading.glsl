in vec3 interpolatedNormal;

out vec4 finalcolor;

void main() {
    vec3 lightDirection = vec3(1.0, 1.0, 1.0);
    float shading = dot(interpolatedNormal, lightDirection);
    shading = max(0.0, shading);  // Clamp negative values to 0.0
    finalcolor = vec4(vec3(shading), 1.0);
}
