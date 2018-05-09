//
//  Renderer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "daVinci.h"
#include "Renderer.hpp"
#include "Window.hpp"
#include "rpmalloc.h"
#include <assert.h>


#ifdef __APPLE__
#define EXPORT __attribute__((visibility("default")))

// TODO: implement a winddows export
#elif _WIN32
#define EXPORT
#endif

Renderer::Renderer(const unsigned short windowWidth, const unsigned short windowHeight)
{
    /* Initialize the library glfw */
    bool isGLFWrdy = glfwInit();
    
    assert(isGLFWrdy && "Could not initialize glfw in " &&  __FILE__);
    
    
    m_Window = std::unique_ptr<Window>(new Window);
    
    if(!m_Window->createWindow(windowWidth, windowHeight))
        fprintf(stderr, "Could not create a GLFW window\n");
    
    glViewport(0, 0, windowWidth, windowHeight);
    
    rpmalloc_initialize();
}


Renderer::~Renderer()
{
    rpmalloc_finalize();
}

void Renderer::render()
{
    GLFWwindow* window = m_Window->getWindow();
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
}


bool Renderer::loadShaderSource(const char* shadeFileName, char** shaderSourceCode)
{
    FILE* file = fopen(shadeFileName, "rb");
    if(!file)
    {
        
        fprintf(stderr, "Error, cannot open file %s\n", shadeFileName);
        fclose(file);
        return false;
    }
    
    long fileSize = getShaderFileSize(file);
    *shaderSourceCode = (char*) rpmalloc(fileSize);
    
    fread(shaderSourceCode, 1, fileSize, file);
    
    fclose(file);
    return true;
}

void Renderer::releaseShaderSource(char* shaderSource)
{
    rpfree(shaderSource);
}

long Renderer::getShaderFileSize(FILE* file)
{
    fseek(file, 0L, SEEK_END);
    long retVal = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return retVal;
}

EXPORT Renderer *NewRenderer(const unsigned short windowWidth, const unsigned short windowHeight)
{
    return new Renderer(windowWidth, windowHeight); // Error prone! If allocation fails.
}

EXPORT void DeleteRenderer(Renderer *renderer)
{
    delete renderer;
}
