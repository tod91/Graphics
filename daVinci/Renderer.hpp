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

class Shader;
class VertexBuffer;
class VertexArray;
class IndexBuffer;
class VertexBufferLayout;
class GLFWwindow;

class EXPORT Renderer
{
public:
    Renderer();
    ~Renderer();
   
   void Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader, GLFWwindow*);
};

#endif /* Renderer_hpp */
