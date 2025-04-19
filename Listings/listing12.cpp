// --- Add this to the includes ---------------------------------------------------
#include "Shader.hpp"

// --- Add this to the variable declarations --------------------------------------
Shader myShader;

// --- Add this in main() after glewInit() and before the rendering loop ----
myShader.createShader("vertex.glsl", "fragment.glsl");

// --- Add this to the rendering loop, right before the call to glBindVertexArray()
glUseProgram(myShader.id());