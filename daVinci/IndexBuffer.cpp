//
//  IndexBuffer.cpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "IndexBuffer.hpp"
#include "GLError.h"

IndexBuffer::IndexBuffer(const unsigned* data, const unsigned count)
: mCount(count)
{
    GLCall(glGenBuffers(1, &mIndices_ID));
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GL_UNSIGNED_INT), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &mIndices_ID))
}

void IndexBuffer::Bind() const
{
     GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndices_ID));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}