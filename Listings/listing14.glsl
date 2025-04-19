// --- Add this to the declarations in the vertex shader
layout(location = 1) in vec3 Color;
out vec3 interpolatedColor;
// And somewhere in its main() function, add this:
interpolatedColor = Color; // Pass interpolated color to fragment shader

// --- Add this to the declarations in the fragment shader
in vec3 interpolatedColor;
// And in its main() function, set the output color like this:
finalcolor = vec4(interpolatedColor, 1.0);
