#include "daVinci.h"
#include "glfw3.h"
#include <iostream>
#include <unistd.h>
using namespace std;

constexpr int  WIDTH = 960;
constexpr int  HEIGHT = 960;

int main()
{
    glfwInit();

    Window window;
    if(!window.createWindow(WIDTH, HEIGHT, "LearnOpenGL"))
        cout << "Could Not create window" << endl;
    
    float positions[] =
    {
         -0.5f, -.5f,  // top right
          0.5f, -0.5f,  // bottom right
          0.5f, 0.5f,  // bottom left
         -0.5f, 0.5f,
    };
    unsigned indices[] = {  // note that we start f  rom 0!
        0, 1, 2,
        0, 2, 3
    };
    
    
    Shader shader("../../../Shaders/VertexShader.vs","../../../Shaders/FragmentShader.fs");
    shader.BuildShaderProgram();
    
    VertexArray va;
    VertexBuffer vbo(positions, sizeof(positions));
    IndexBuffer ibo(indices, 6);
    VertexBufferLayout layout;
    
    layout.Push(GLNumber::FLOAT, 2, false);
    va.AddBuffer(vbo, layout);
    
    Renderer renderer;
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        renderer.Draw(va, ibo, shader, window.getWindow());
    }
    
    return 0;
}
