#include "daVinci.h"
#include "glfw3.h"
#include <iostream>
#include <unistd.h>
#define WIDTH 960
#define HEIGHT 720

using namespace std;

int main()
{
    glfwInit();
    Window window;
    if(!window.createWindow(WIDTH, HEIGHT, "LearnOpenGL"))
    {
        cout << "Could Not create window" << endl;
    }
    
    float positions[] =
    {
         -0.5f, 0.0f,  // top right
          0.0f, 0.5f,  // bottom right
          0.5f, 0.0f,  // bottom left
    };
    unsigned indices[] = {  // note that we start f  rom 0!
        0, 1, 2
    };
    
    
    Shader shader("../../../Shaders/VertexShader.vs","../../../Shaders/FragmentShader.fs");
    shader.BuildShaderProgram();
    
    VertexArray va;
    VertexBuffer vbo(positions, sizeof(positions));
    IndexBuffer ibo(indices, 3);
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
