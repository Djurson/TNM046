/*
 * A C++ framework for OpenGL programming in TNM046 for MT1
 *
 * This is a small, limited framework, designed to be easy to use for students in an introductory
 * computer graphics course in the first year of a M Sc curriculum. It uses custom code for some
 * things that are better solved by external libraries like GLM, but the emphasis is on simplicity
 * andreadability, not generality.
 *
 * For the window management, GLFW 3.x is used for convenience.
 * The framework should work in Windows, MacOS X and Linux.
 * GLEW is used for handling platform specific OpenGL extensions.
 * This code depends only on GLFW, GLEW, and OpenGL libraries.
 * OpenGL 3.3 or higher is required.
 *
 * Authors: Stefan Gustavson (stegu@itn.liu.se) 2013-2015
 *          Martin Falk (martin.falk@liu.se) 2021
 *
 * This code is in the public domain.
 */
#if defined(WIN32) && !defined(_USE_MATH_DEFINES)
#define _USE_MATH_DEFINES
#endif

// File and console I/O for logging and error reporting
#include <iostream>
// Math header for trigonometric functions
#include <cmath>

// glew provides easy access to advanced OpenGL functions and extensions
#include <GL/glew.h>

// GLFW 3.x, to handle the OpenGL window
#include <GLFW/glfw3.h>

#include "Utilities.hpp"
#include <vector>
#include <array>
#include "Shader.hpp"
#include "TriangleSoup.hpp"


std::array<float, 16> mat4mult(const std::array<float, 16>& m2, const std::array<float, 16>& m1);
std::array<float, 16> mat4rotx(float angle);
std::array<float, 16> mat4roty(float angle);
std::array<float, 16> mat4rotz(float angle);
std::array<float, 16> mat4scale(float scale);
std::array<float, 16> mat4translate(float x, float y, float z);
void mat4print(const std::array<float, 16>& m);

/*
 * main(int argc, char* argv[]) - the standard C++ entry point for the program
 */
int main(int, char*[]) {


    int width, height;

    // Initialise GLFW
    glfwInit();

    const GLFWvidmode* vidmode;  // GLFW struct to hold information about the display
    // Determine the desktop size
    vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    // Make sure we are getting a GL context of at least version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Enable the OpenGL core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Open a square window (aspect 1:1) to fill half the screen height
    GLFWwindow* window = glfwCreateWindow(vidmode->height / 2, vidmode->height / 2, "GLprimer", nullptr, nullptr);
    if (!window) {
        std::cout << "Unable to open window. Terminating.\n";
        glfwTerminate();  // No window was opened, so we can't continue in any useful way
        return -1;
    }

    // Make the newly created window the "current context" for OpenGL
    // (This step is strictly required or things will simply not work)
    glfwMakeContextCurrent(window);

    // Initialize glew
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cerr << "Error: " << glewGetErrorString(err) << "\n";
        glfwTerminate();
        return -1;
    }

    Shader myShader;
    myShader.createShader("../shaders/vertex.glsl", "../shaders/fragment.glsl");

    glfwSwapInterval(0);  // Do not wait for screen refresh between frames


    // Show some useful information on the GL context
    std::cout << "GL vendor:       " << glGetString(GL_VENDOR)
              << "\nGL renderer:     " << glGetString(GL_RENDERER)
              << "\nGL version:      " << glGetString(GL_VERSION)
              << "\nDesktop size:    " << vidmode->width << " x " << vidmode->height << "\n";

    // Do this before the rendering loop
    GLint locationTime = glGetUniformLocation(myShader.id(), "time");
    if (locationTime == -1) {  // If the variable is not found, -1 is returned
        std::cout << "Unable to locate variable 'time' in shader!\n";
    }

    TriangleSoup sphere;

    sphere.createSphere(1.0f, 20);

    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Set the clear color to a dark gray (RGBA)
        glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

        // Clear the color and depth buffers for drawing
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Visa FPS
        util::displayFPS(window);
        /* ---- Rendering code should go here ---- */
        glUseProgram(myShader.id());

        float time = static_cast<float>(glfwGetTime());  // Number of seconds since the program was started
        glUseProgram(myShader.id());            // Activate the shader to set its variables
        glUniform1f(locationTime, time);        // Copy the value to the shader program

        // Creating the variables for the matrix multiplication
        std::array<GLfloat, 16> R1 = mat4roty((time * 3));

        // Sending the matrix mult to the shaders
        std::array<float, 16> matTransformation = R1;
        std::array<GLfloat, 16> matRotY = mat4roty(time);
        GLint locationMatTRAN = glGetUniformLocation(myShader.id(), "MAT_TRAN");
        glUniformMatrix4fv(locationMatTRAN, 1, GL_FALSE,
                           matTransformation.data());  // Copy the value

        std::array<GLfloat, 16> matT = matTransformation;
        GLint locationT = glGetUniformLocation(myShader.id(), "T");
        glUseProgram(myShader.id());  // Activate the shader to set its variables
        glUniformMatrix4fv(locationT, 1, GL_FALSE, matT.data());  // Copy the value

        sphere.render();


        // Swap buffers, display the image and prepare for next frame
        glfwSwapBuffers(window);

        // Poll events (read keyboard and mouse input)
        glfwPollEvents();

        // Exit if the ESC key is pressed (and also if the window is closed)
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }

    // Close the OpenGL window and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}

std::array<float, 16> mat4mult(const std::array<float, 16>& m2, const std::array<float, 16>& m1) {
    std::array<float, 16> result;

    // Your code goes here: compute and set each element of result, e.g.:
    //
    result[0] = m1[0] * m2[0] + m1[1] * m2[4] + m1[2] * m2[8] + m1[3] * m2[12];
    result[1] = m1[0] * m2[1] + m1[1] * m2[5] + m1[2] * m2[9] + m1[3] * m2[13];
    result[2] = m1[0] * m2[2] + m1[1] * m2[6] + m1[2] * m2[10] + m1[3] * m2[14];
    result[3] = m1[0] * m2[3] + m1[1] * m2[7] + m1[2] * m2[11] + m1[3] * m2[15];

    result[4] = m1[4] * m2[0] + m1[5] * m2[4] + m1[6] * m2[8] + m1[7] * m2[12];
    result[5] = m1[4] * m2[1] + m1[5] * m2[5] + m1[6] * m2[9] + m1[7] * m2[13];
    result[6] = m1[4] * m2[2] + m1[5] * m2[6] + m1[6] * m2[10] + m1[7] * m2[14];
    result[7] = m1[4] * m2[3] + m1[5] * m2[7] + m1[6] * m2[11] + m1[7] * m2[15];

    result[8] = m1[8] * m2[0] + m1[9] * m2[4] + m1[10] * m2[8] + m1[11] * m2[12];
    result[9] = m1[8] * m2[1] + m1[9] * m2[5] + m1[10] * m2[9] + m1[11] * m2[13];
    result[10] = m1[8] * m2[2] + m1[9] * m2[6] + m1[10] * m2[10] + m1[11] * m2[14];
    result[11] = m1[8] * m2[3] + m1[9] * m2[7] + m1[10] * m2[11] + m1[11] * m2[15];

    result[12] = m1[12] * m2[0] + m1[13] * m2[4] + m1[14] * m2[8] + m1[15] * m2[12];
    result[13] = m1[12] * m2[1] + m1[13] * m2[5] + m1[14] * m2[9] + m1[15] * m2[13];
    result[14] = m1[12] * m2[2] + m1[13] * m2[6] + m1[14] * m2[10] + m1[15] * m2[14];
    result[15] = m1[12] * m2[3] + m1[13] * m2[7] + m1[14] * m2[11] + m1[15] * m2[15];
    //
    // etc. for the remaining 15 elements.
    return result;
}

std::array<float, 16> mat4rotx(float angle) {
    std::array<GLfloat, 16> matT_X = {1.0f,     0.0f,           0.0f,           0.0f,        
                                      0.0f,     cos(angle),     sin(angle),     0.0f, 
                                      0.0f,     -sin(angle),    cos(angle),     0.0f,
                                      0.0f,     0.0f,           0.0f,           1.0f};
    return matT_X;
}

std::array<float, 16> mat4roty(float angle) {
    std::array<float, 16> matT_Y = {cos(angle), 0.0f,   -sin(angle),    0.0f, 
                                    0.0f,       1.0f,   0.0f,           0.0f,
                                    sin(angle), 0.0f,   cos(angle),     0.0f, 
                                    0.0f,       0.0f,   0.0f,           1.0f};
    return matT_Y;
}

std::array<float, 16> mat4rotz(float angle) {
    std::array<GLfloat, 16> matT_Z = {cos(angle),   sin(angle),     0.0f,   0.0f, 
                                      -sin(angle),  cos(angle),     0.0f,   0.0f,           
                                      0.0f,         0.0f,           1.0f,   0.0f,
                                      0.0f,         0.0f,           0.0f,   1.0f};
    return matT_Z;
}

std::array<float, 16> mat4scale(float scale) {
    std::array<GLfloat, 16> matT_S = {scale, 0.0f, 0.0f,  0.0f, 
                                      0.0f, scale, 0.0f, 0.0f,
                                      0.0f,  0.0f, scale, 0.0f, 
                                      0.0f, 0.0f,  0.0f, 1.0f};
    return matT_S;
}

std::array<float, 16> mat4translate(float x, float y, float z) {
    std::array<GLfloat, 16> matT_T = {1.0f, 0.0f, 0.0f, 0.0f, 
                                      0.0f, 1.0f, 0.0f, 0.0f,
                                      0.0f, 0.0f, 1.0f, 0.0f, 
                                      x,    y,    z,    1.0f};
    return matT_T;
}

void mat4print(const std::array<float, 16>& m) {
    printf("Matrix:\n");
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[0], m[4], m[8], m[12]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[1], m[5], m[9], m[13]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[2], m[6], m[10], m[14]);
    printf("%6.2f %6.2f %6.2f %6.2f\n", m[3], m[7], m[11], m[15]);
    printf("\n");
}

std::array<float, 16> mat4identity() {
    std::array<float, 16> temp = {1.0f, 0.0f, 0.0f, 0.0f, 
                                  0.0f, 1.0f, 0.0f, 0.0f,
                                  0.0f, 0.0f, 1.0f, 0.0f, 
                                  0.0f, 0.0f, 0.0f, 1.0f};
    return temp;
}