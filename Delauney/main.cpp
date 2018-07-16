//
//  main.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/4/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
 // MOVE TO daVINCI
//#if defined _WIN32
//#include <glad.h>
//#endif

#include "Delaunay.hpp"
#include "daVinci.h"
#include <dlfcn.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef void* (*Render_creator)(const unsigned short, const unsigned short);

typedef void (*Delete_Renderer)(void*);

int main(int argc, char * argv[])
{
//    Delaunay delone;
//    delone.Triangulate("../../../ProjectDelone/SamplePointFiles/RANDOM.DAT");
//
    Renderer obj(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    obj.Print();
    obj.render();
//    const char* name = "../../../ProjectDelone/Shaders/VertexShader.vs";
//    FILE* file = fopen(name, "r");
//    if(!file)
//    {
//        fprintf(stderr, "Error, cannot open file %s\n", name);
//        fclose(file);
////        return FAILED;
//    }
//    char tempArr[512];

    return 0;
}
