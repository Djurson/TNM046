// Do this before the rendering loop
GLint locationTime = glGetUniformLocation(myShader.id(), "time");
if (locationTime == -1) {  // If the variable is not found, -1 is returned
    std::cout << "Unable to locate variable 'time' in shader!\n";
}

// Do this in the rendering loop to update the uniform variable "time"
float time = static_cast<float>(glfwGetTime());  // Number of seconds since the program was started
glUseProgram(myShader.id());                     // Activate the shader to set its variables
glUniform1f(locationTime, time);                 // Copy the value to the shader program
