//
//  Renderer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "Window.hpp"
#include "VertexBufferLayout.hpp"
#include <glfw3.h>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader, GLFWwindow* window)
{
    va.Bind();
    ibo.Bind();
    shader.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
    glfwSwapBuffers(window);
    glfwPollEvents();
}
