layout(location=0) in vec3 Position;
layout(location=1) in vec3 Normal;
layout(location=2) in vec2 TexCoord;

out vec3 interpolatedNormal;
out vec2 st;

void main() {
	gl_Position = vec4(Position, 1.0); // Special, required output
	interpolatedNormal = Normal; // Will be interpolated across the triangle
	st = TexCoord; // Will also be interpolated across the triangle
}
