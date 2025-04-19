#version 330
uniform sampler2D tex;  // A uniform variable to identify the texture

in vec2 st;             // Interpolated texture coords, sent from vertex shader

void main() {
    finalcolor = texture(tex, st);  // Use the texture to set the surface color
}
