//
//  VertexBufferLayout.hpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef VertexBufferLayout_hpp
#define VertexBufferLayout_hpp
#include "ExportDefine.h"
#include "GLError.h"
#include <vector>

enum GLNumber
{
    FLOAT = GL_FLOAT, U_BYTE = GL_UNSIGNED_BYTE, U_INT = GL_UNSIGNED_INT
};

struct VertexBufferElement
{
    unsigned type;
    int      count;
    bool     normalized;
    
    static unsigned GetSizeType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT:         return sizeof(GLfloat);
            case GL_UNSIGNED_INT:  return sizeof(GLuint);
            case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
        }
        
        puts("Error: unsupported VBO type");
        return 0;
    }
};

class EXPORT VertexBufferLayout
{
public:
    VertexBufferLayout();
    ~VertexBufferLayout();
    
    void    Push(GLNumber num, int count, bool normalized);
    GLsizei GetStride() const { return  m_Stride; }
    
    //Optimize this with a move.
   const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
    
private:
    std::vector<VertexBufferElement> m_Elements;
    GLsizei m_Stride;
};

#endif /* VertexBufferLayout_hpp */
