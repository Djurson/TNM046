// --- Put this before the rendering loop
// Locate the sampler2D uniform in the shader program
GLint locationTex = glGetUniformLocation(myShader.id(), "tex");
// Generate one texture object with data from a TGA file
Texture myTexture;
myTexture.createTexture("textures/earth.tga");

// --- Put this in the rendering loop
// Draw the TriangleSoup object mySphere
// with a shader program that uses a texture

glBindTexture(GL_TEXTURE_2D, myTexture.id());

glUseProgram(myShader.id());
glUniform1i(locationTex, 0);
mySphere.render();

// restore previous state (no texture, no shader)
glBindTexture(GL_TEXTURE_2D, 0);
glUseProgram(0);
