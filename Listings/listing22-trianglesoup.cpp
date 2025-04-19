class TriangleSoup {
private:
    GLuint vao_;                        // Vertex array object, the main handle for geometry
    int nverts_;                        // Number of vertices in the vertex array
    int ntris_;                         // Number of triangles in the index array (may be zero)
    GLuint vertexbuffer_;               // Buffer ID to bind to GL_ARRAY_BUFFER
    GLuint indexbuffer_;                // Buffer ID to bind to GL_ELEMENT_ARRAY_BUFFER
    std::vector<GLfloat> vertexarray_;  // Vertex array on interleaved format: x y z nx ny nz s t
    std::vector<GLuint> indexarray_;    // Element index array
};
