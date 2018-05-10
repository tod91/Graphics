//
//  Renderer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <memory>

class Window;

class Renderer
{
public:
    Renderer(const unsigned short windowWidth, const unsigned short windowHeight);
    ~Renderer();
    
    void render();
    
    void releaseShaderSource(char* shaderSource);
    void initGLResources();
    void compileShader();
private: // Methods
    
    bool    loadShaderSource(const char* shaderFileName, char** shaderSourceCode);
    long    getShaderFileSize(FILE* fileHandle);
    
private: // Data
    unsigned VBO;
    
    std::unique_ptr<Window> m_Window;
};

#endif /* Renderer_hpp */
