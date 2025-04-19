// --- Add this after the other vertex array declarations --------------
const std::vector<GLfloat> colorArrayData = {
    1.0f, 0.0f, 0.0f,  // Red
    0.0f, 1.0f, 0.0f,  // Green
    0.0f, 0.0f, 1.0f,  // Blue
};

// --- Add this after glEnableVertexAttribArray(0) ---------------------
// Generate a second vertex buffer, activate it and copy data to it
GLuint colorBufferID = 0;  // Vertex colors
glGenBuffers(1, &colorBufferID);
glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
glBufferData(GL_ARRAY_BUFFER, colorArrayData.size() * sizeof(GLfloat), colorArrayData.data(),
             GL_STATIC_DRAW);
// Tell OpenGL how the data is stored in our color buffer
// Attribute #1, 3 dimensions (R,G,B -> vec3 in the shader),
// type GL_FLOAT, not normalized, stride 0, start at element 0
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
// Enable a second attribute (in this case, to hold vertex colors)
glEnableVertexAttribArray(1);

// ------------------------------------------------------------------------
// ---- Put the following code directly after the rendering loop next to the others
// release the color buffers
glDeleteBuffers(1, &colorBufferID);
