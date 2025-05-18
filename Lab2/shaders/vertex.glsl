#version 330 core

uniform float time;
uniform mat4 T;
uniform mat4 T_X;
uniform mat4 T_Z;
uniform mat4 T_Y;
uniform mat4 T_S;
uniform mat4 MAT_TRAN;

layout(location = 0) in vec3 Position;
layout(location = 1) in vec3 Color;

out vec3 interpolatedColor;

void main(){
	gl_Position = MAT_TRAN * vec4(Position, 4.0);
	interpolatedColor = Color;
}