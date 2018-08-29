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
         -0.5f, -0.5f, 1.0, 1.0,
          0.5f, -0.5f, 1.0, 0.0,
          0.5f,  0.5f, 0.0, 0.0,
         -0.5f,  0.5f, 0.0, 1.0
    };
    unsigned indices[] = {  // note that we start from 0!
        0, 1, 2,
        0, 2, 3
    };
    
    
    Shader shader("../../../Shaders/VertexShader.vs","../../../Shaders/FragmentShader.fs");
    shader.BuildShaderProgram();
    shader.Bind();
    
    VertexBufferLayout layout;
    VertexArray va;
    VertexBuffer vbo(positions, sizeof(positions));
    IndexBuffer ibo(indices, 6);
    
    
    Texture texture("../../../Textures/wall.jpg");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);
    shader.SetUniform4f("u_Color", 0.0, 1.0, 0.0, 0.0);
    
    
    layout.Push(GLNumber::FLOAT, 2, false);
    layout.Push(GLNumber::FLOAT, 2, false);
    va.AddBuffer(vbo, layout);
    
    
    Renderer renderer;
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        renderer.Draw(va, ibo, shader, window.getWindow());
    }
    
    return 0;
}
