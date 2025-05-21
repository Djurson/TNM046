#version 330 core

//uniform float time;
uniform mat4 T;

out vec4 finalcolor;

in vec3 interpolatedNormal;
in vec2 st;

void main() {
	finalcolor = vec4(interpolatedNormal * 0.5 + 0.5, 1);
}