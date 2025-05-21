#version 330 core

uniform mat4 T;

out vec4 finalcolor;

in vec3 interpolatedNormal;
in vec2 st;
in vec3 Lin;

void main() {
	vec3 L = Lin;
	vec3 V = vec3(0.0f,0.0f,1.0f);
	vec3 N = interpolatedNormal;

	vec3 colorRGB = vec3(0.75f, 0.5f, 0.0f);
	vec3 colorGreyScale = vec3(1.0f, 1.0f, 1.0f);

	float n = 100;

	vec3 ka = 0.9f * colorRGB;
	vec3 Ia = 0.5f * colorGreyScale;
	vec3 kd = 1.0f * colorRGB;
	vec3 Id = 0.8f * colorGreyScale;
	vec3 ks = 1.0f * colorGreyScale;
	vec3 Is = 0.9f * colorGreyScale;

	N = normalize(N);
	L = normalize(L);
	V = normalize(V);
	vec3 R = 2.0 * dot(N, L) * N - L;
	float dotNL = max(dot(N, L), 0.0);
	float dotRV = max(dot(R, V), 0.0);
	if (dotNL == 0.0) {
		dotRV = 0.0;
	}
	vec3 shadedcolor = Ia * ka + Id * kd * dotNL + Is * ks * pow(dotRV, n);
	finalcolor = vec4(shadedcolor, 1.0);
}