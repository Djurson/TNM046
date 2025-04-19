layout(location = 1) in vec3 Normal;

out vec3 interpolatedNormal;

uniform mat4 T;

vec3 transformedNormal = mat3(T) * Normal;
interpolatedNormal = normalize(transformedNormal);
