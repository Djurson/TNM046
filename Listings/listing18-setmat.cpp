std::array<GLfloat, 16> matT = {
	1.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 1.0f
};

GLint locationT = glGetUniformLocation(myShader.id(), "T");
glUseProgram(myShader.id());  // Activate the shader to set its variables
glUniformMatrix4fv(locationT, 1, GL_FALSE, matT.data());  // Copy the value
