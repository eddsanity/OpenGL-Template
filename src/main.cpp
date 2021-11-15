#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stdio.h>

#include <util/common.hpp>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

void framebuffer_size_callback(GLFWwindow* glfw_window, i32 window_width, i32 window_height);
void glfw_error_callback(i32 error_code, const char* error_msg);
void processInput(GLFWwindow* glfw_window);

int main()
{
    glfwSetErrorCallback(glfw_error_callback);

    // initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a WINDOW_WIDTH x WINDOW_HEIGHT GLFW Window
    auto glfw_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL template", nullptr, nullptr);
    defer(glfwTerminate());
    if (glfw_window == nullptr)
    {
        printf("[GLFW]: Window creation failed\n");
        return -1;
    }
    glfwMakeContextCurrent(glfw_window);
    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

    // load openGL function pointers
    if (!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
    {
        printf("[GLAD]: Initialization failed\n");
        return -1;
    }

    // render loop
    while (!glfwWindowShouldClose(glfw_window))
    {
        processInput(glfw_window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap the front and back buffers (i.e. render the back buffer)
        glfwSwapBuffers(glfw_window);

        // poll for IO events
        glfwPollEvents();
    }


    return 0;
}

void framebuffer_size_callback(GLFWwindow* glfw_window, i32 window_width, i32 window_height)
{
    glViewport(0, 0, window_width, window_height);
}

void glfw_error_callback(i32 error_code, const char* error_msg)
{
    printf("[GLFW]: %s\n", error_msg);
    printf("[GLFW]: error code '%d'\n", error_code);
}

void processInput(GLFWwindow* glfw_window)
{
    if (glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glfw_window, true);
}