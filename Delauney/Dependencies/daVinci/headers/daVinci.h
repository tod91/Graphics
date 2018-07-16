//
//  daVinci.h
//  daVinci
//
//  Created by Todor Ivanov on 5/9/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef daVinci_h
#define daVinci_h
#include <stdio.h>
#include <memory>
class Window;

class  Renderer
{
public:
    Renderer(const unsigned short windowWidth, const unsigned short windowHeight);
    ~Renderer();
    
    void render();
    
    void releaseShaderSource(char* shaderSource);
    void initGLResources();
    void compileShader();
    void Print();
private: // Methods
    
    bool    loadShaderSource(const char* shaderFileName, char** shaderSourceCode);
    long    getShaderFileSize(FILE* fileHandle);
    
private: // Data
    unsigned VBO;
    
    std::unique_ptr<Window> m_Window;
};

#endif /* daVinci_h */
