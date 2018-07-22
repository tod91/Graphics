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

static const char* ConvertGLErrToString(GLenum err)
{
    switch (err) {
        case 0x0500: return "GL_INVALID_ENUM";
        case 0x0501: return "GL_INVALID_VALUE";
        case 0x0502: return "GL_INVALID_OPERATION";
        case 0x0505: return "GL_OUT_OF_MEMORY";

        default: return "UNKNOWN ERROR";
    }
}

static void GLClearError()
{
    while(glGetError());
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    if(GLenum error = glGetError())
    {
        const char* errStr = ConvertGLErrToString(error);
        printf("[OpenGL Error] (%s) %s %s  %d\n", errStr, function, file, line);
        return false;
    }
    return true;
}
#else
#define GLCall(x) x;
#define ASSERT(x) 

#endif
#endif /* GLError_h */
