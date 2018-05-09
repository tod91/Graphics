//
//  Window.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "Window.hpp"

Window::Window()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}


Window::~Window()
{
    glfwTerminate();
}


bool Window::createWindow(const unsigned short width, const unsigned short heigh)
{
    window = glfwCreateWindow(width, heigh, "Delaunay Triangulation", NULL, NULL);
    
    if(!window)
        return false;
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    return true;
}