//
//  GLError.h
//  daVinci
//
//  Created by Todor Ivanov on 5/13/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef GLError_h
#define GLError_h

#include <OpenGL/gl3.h>
#ifdef DEBUG
#include "debugbreak.h"
#include <stdio.h>
#define ASSERT(x) if(!(x)) debug_break();
#define GLCall(x) GLClearError();\
x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__));


static void GLClearError()
{
    while(glGetError());
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    if(GLenum error = glGetError())
    {
        printf("[OpenGL Error] (%d) %s %s  %d\n", error, function, file, line);
        return false;
    }
    return true;
}
#else
#define GLCall(x) x;
#define ASSERT(x) 

#endif
#endif /* GLError_h */
