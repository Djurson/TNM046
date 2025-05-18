#version 330 core

uniform float time;
uniform mat4 T;
uniform mat4 T_Z;
uniform mat4 T_Y;
uniform mat4 T_S;
in vec3 interpolatedColor;
out vec4 finalcolor;

void main() {
	finalcolor = vec4(1.0, 0.5, 0.0, 1.0);
	finalcolor = vec4(interpolatedColor, 1.0);
}