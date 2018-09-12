//
//  Renderer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "ExportDefine.h"

class VertexArray;
class IndexBuffer;
class Shader;
class GLFWwindow;

class EXPORT Renderer
{
public:
    Renderer(bool wireFrameMode = false);
    ~Renderer();
    
    void DrawArrays(const VertexArray& va, const Shader& shader, GLFWwindow* window, int size);
    void Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader, GLFWwindow* window);
};

#endif /* Renderer_hpp */
