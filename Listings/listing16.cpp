// Generate 1 Vertex array object, put the resulting identifier in vertexArrayID
glGenVertexArrays(1, &vertexArrayID);
// Activate the vertex array object
glBindVertexArray(vertexArrayID);

// Create the vertex buffer objects for attribute locations 0 and 1
// (the list of vertex coordinates and the list of vertex colors).
GLuint vertexBufferID = createVertexBuffer(0, 3, vertexArrayData);
GLuint colorBufferID = createVertexBuffer(1, 3, colorArrayData);
// Create the index buffer object (the list of triangles).
GLuint indexBufferID = createIndexBuffer(indexArrayData);

// Deactivate the vertex array object again to be nice
glBindVertexArray(0);

// ------------------------------------------------------------------------
// ---- Put the following code directly after the rendering loop
// release the vertex array and the buffers
glDeleteVertexArrays(1, &vertexArrayID);
glDeleteBuffers(1, &vertexBufferID);
glDeleteBuffers(1, &colorBufferID);
glDeleteBuffers(1, &indexBufferID);
