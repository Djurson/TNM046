#include <vector>
// ------------------------------------------------------------------------
// --- Put this code at the top of your main() function.
// Vertex coordinates (x,y,z) for three vertices
const std::vector<GLfloat> vertexArrayData = {
    -1.0f, -1.0f, 0.0f,  // First vertex, xyz
    1.0f,  -1.0f, 0.0f,  // Second vertex, xyz
    0.0f,  1.0f,  0.0f   // Third vertex, xyz
};
const std::vector<GLuint> indexArrayData = {0, 1, 2};

// ------------------------------------------------------------------------
// ---- Put this code after glewInit(), but before the rendering loop

// Generate 1 Vertex array object, put the resulting identifier in vertexArrayID
GLuint vertexArrayID = 0;
glGenVertexArrays(1, &vertexArrayID);
// Activate the vertex array object
glBindVertexArray(vertexArrayID);

// Generate 1 buffer, put the resulting identifier in vertexBufferID
GLuint vertexBufferID = 0;
glGenBuffers(1, &vertexBufferID);
// Activate the vertex buffer object
glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
// Present our vertex coordinates to OpenGL
glBufferData(GL_ARRAY_BUFFER, vertexArrayData.size() * sizeof(GLfloat), vertexArrayData.data(),
             GL_STATIC_DRAW);
// Specify the format of the data in the vertex buffer, and copy the data.
// The six arguments specify, from left to right:
// Attribute 0, must match the "layout" statement in the shader.
// Dimensions 3, means 3D (x,y,z) - this becomes a vec3 in the shader.
// Type GL_FLOAT, means we have "float" input data in the array.
// GL_FALSE means "no normalization". This has no meaning for float data.
// Stride 0, meaning (x,y,z) values are packed tightly together without gaps.
// Array buffer offset 0 means our data starts at the first element.
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
// Enable vertex attribute array 0 to send xyz coordinates to the shader.
glEnableVertexAttribArray(0);

// Generate 1 buffer, put the resulting identifier in indexBufferID
GLuint indexBufferID = 0;
glGenBuffers(1, &indexBufferID);
// Activate (bind) the index buffer and copy data to it.
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
// Present our vertex indices to OpenGL
glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexArrayData.size() * sizeof(GLuint), indexArrayData.data(),
             GL_STATIC_DRAW);
// Deactivate the vertex array object again to be nice
glBindVertexArray(0);

// ------------------------------------------------------------------------
// ---- Put the following code in the rendering loop
// Activate the vertex array object we want to draw (we may have several)
glBindVertexArray(vertexArrayID);
// Draw our triangle with 3 vertices.
// When the last argument of glDrawElements is nullptr, it means
// "use the previously bound index buffer". (This is not obvious.)
// The index buffer is part of the VAO state and is bound with it.
glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

// ------------------------------------------------------------------------
// ---- Put the following code directly after the rendering loop (before glfwDestroyWindow())
// release the vertex and index buffers as well as the vertex array
glDeleteVertexArrays(1, &vertexArrayID);
glDeleteBuffers(1, &vertexBufferID);
glDeleteBuffers(1, &indexBufferID);
