#version 330 core

//uniform float time;
uniform mat4 T;

out vec4 finalcolor;

in vec3 interpolatedNormal;
in vec2 st;

void main() {
	/*
	vec3 L = normalize(mat3(T) * vec3(0.0f, 0.0f, 1.0f));
	vec3 V = vec3(0.0f,0.0f,1.0f);
	vec3 N = interpolatedNormal;

	vec3 colorRGB = vec3(0.7f, 0.0f, 0.7f);
	vec3 colorGreyScale = vec3(1.0f, 1.0f, 1.0f);

	float n = 100;

	vec3 ka = 0.9f * colorRGB;
	vec3 Ia = 0.5f * colorGreyScale;
	vec3 kd = 1.0f * colorRGB;
	vec3 Id = 0.8f * colorGreyScale;
	vec3 ks = 1.0f * colorGreyScale;
	vec3 Is = 0.9f * colorGreyScale;

	// This assumes that N, L and V are normalized.
	N = normalize(N);
	L = normalize(L);
	V = normalize(V);
	vec3 R = 2.0 * dot(N, L) * N - L;   // Could also have used the function reflect()
	float dotNL = max(dot(N, L), 0.0);  // If negative, set to zero
	float dotRV = max(dot(R, V), 0.0);
	if (dotNL == 0.0) {
		dotRV = 0.0;  // Do not show highlight on the dark side
	}
	vec3 shadedcolor = Ia * ka + Id * kd * dotNL + Is * ks * pow(dotRV, n);
	finalcolor = vec4(shadedcolor, 1.0);
	//guuuuuuuuuh?!
	*/

	finalcolor = vec4(interpolatedNormal * 0.5 + 0.5, 1);
}