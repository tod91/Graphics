//
//  VertexBuffer.cpp
//  daVinci
//
//  Created by Todor Ivanov on 5/13/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "VertexBuffer.hpp"
#include "GLError.h"

VertexBuffer::VertexBuffer(const void* data, const unsigned size)
{
    GLCall(glGenBuffers(1, &m_VBO_ID));
    Bind();
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
 
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_VBO_ID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO_ID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
