in vec3 interpolatedNormal;

out vec4 finalcolor;

void main() {
	finalcolor = vec4(vec3(interpolatedNormal.z), 1.0);
}
