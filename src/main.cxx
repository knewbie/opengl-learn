#include <iostream>
#include <GL/gl.h>
#include <GLFW/glfw3.h>


const int WIN_W = 800;
const int WIN_H = 600;

void frame_size_callback(GLFWwindow *win, int width, int height) 
{
    glViewport(0,0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // for macos
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(WIN_W,WIN_H, "LearnGL", nullptr, nullptr);
    if(window == nullptr) {
        std::cout<<"failed to create glfw window"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    // set the callback when window size changed
    glfwSetFramebufferSizeCallback(window, frame_size_callback);

    glViewport(0,0, WIN_W,WIN_H);


    glClearColor(0.2f, .3f, .2f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = {
        -0.5f, -0.5f, .0f,
        0.5f, -0.5f, .0f,
        .0f, 0.5f, .0f,
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    while(!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // render

        glfwPollEvents();
        
        // swap buffer
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}