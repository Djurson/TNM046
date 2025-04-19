/*
 * A C++ framework for OpenGL programming in TNM046 for MT1
 *
 * Authors: Stefan Gustavson (stegu@itn.liu.se) 2013-2015
 *          Martin Falk (martin.falk@liu.se) 2021
 *
 * This code is in the public domain.
 */
#include <GL/glew.h>     // provides easy access to advanced OpenGL functions and extensions
#include <GLFW/glfw3.h>  // GLFW handles the window and user input

int main(int argc, char* argv[]) {
    glfwInit();  // Initialise GLFW

    const GLFWvidmode* vidmode;  // GLFW struct to hold information about the display
    vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());  // Determine the desktop size
    // Make sure we are getting an OpenGL context of at least version 3.3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Open a square window (aspect 1:1) of size 500x500 pixels
    GLFWwindow* window = glfwCreateWindow(500, 500, "GLprimer", nullptr, nullptr);
    if (!window) {
        glfwTerminate();  // No window was opened, so we can't continue
        return -1;
    }
    // Make the newly created window the "current context"
    glfwMakeContextCurrent(window);
    // Initialize glew
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        glfwTerminate();
        return -1;
    }

    // Set the viewport (specify which pixels we want to draw to)
    int width, height;  // width and height of the window
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);  // Render to the entire window
    glfwSwapInterval(0);              // Do not wait for screen refresh between frames

    // Rendering loop: exit if window is closed by the user
    while (!glfwWindowShouldClose(window)) {
        // Set the clear color to a dark gray (RGBA)
        glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
        // Clear the color and depth buffers for drawing
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* ---- (Rendering code should go here) ---- */

        // Swap buffers, i.e. display the image and prepare for next frame.
        glfwSwapBuffers(window);

        glfwPollEvents();  // Poll events (read keyboard and mouse input)
        // Exit also if the ESC key is pressed.
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }

    // Close the OpenGL window, terminate GLFW, and quit.
    glfwDestroyWindow(window);
    glfwTerminate();
}
