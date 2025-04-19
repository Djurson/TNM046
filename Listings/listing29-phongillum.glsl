// vec3 L is the light direction
// vec3 V is the view direction - (0,0,1) in view space
// vec3 N is the normal
// vec3 R is the computed reflection direction
// float n is the ``shininess'' parameter
// vec3 ka is the ambient reflection color
// vec3 Ia is the ambient illumination color
// vec3 kd is the diffuse surface reflection color
// vec3 Id is the diffuse illumination color
// vec3 ks is the specular surface reflection color
// vec3 Is is the specular illumination color

// This assumes that N, L and V are normalized.
vec3 R = 2.0 * dot(N, L) * N - L;   // Could also have used the function reflect()
float dotNL = max(dot(N, L), 0.0);  // If negative, set to zero
float dotRV = max(dot(R, V), 0.0);
if (dotNL == 0.0) {
	dotRV = 0.0;  // Do not show highlight on the dark side
}
vec3 shadedcolor = Ia * ka + Id * kd * dotNL + Is * ks * pow(dotRV, n);
finalcolor = vec4(shadedcolor, 1.0);
