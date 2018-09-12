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
         0.5f,  0.5f,    1.0f, 1.0f, // top right
         0.5f, -0.5f,    1.0f, 0.0f, // bottom right
        -0.5f, -0.5f,    0.0f, 0.0f, // bottom left
        -0.5f,  0.5f,    0.0f, 1.0f  // top left
    };
    unsigned indices[] = {  // note that we start from 0!
        0, 1, 3,
        1, 2, 3
    };

    VertexBufferLayout layout;
    VertexArray va;

    VertexBuffer vbo(positions, sizeof(positions));
    IndexBuffer ibo(indices, 6);
    
    layout.Push(GLNumber::FLOAT, 2, false);
    layout.Push(GLNumber::FLOAT, 2, false);
    va.AddBuffer(vbo, layout);
    
    
    Shader shader("../../../Shaders/VertexShader.vs","../../../Shaders/FragmentShader.fs");
    shader.BuildShaderProgram();
    shader.Bind();
    
    Texture texture("../../../Textures/container.jpg");
    Texture smiley("../../../Textures/awesomeface.png", false, 1);
    texture.Bind();
    smiley.Bind(1);
    shader.SetUniform1i("containerTex", 0);
    shader.SetUniform1i("smileTex", 1);
    //shader.SetUniform4f("u_Color", 0.0, 1.0, 0.0, 0.0);
    
    Renderer renderer;
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        renderer.Draw(va, ibo, shader, window.getWindow());
    }
    
    return 0;
}
