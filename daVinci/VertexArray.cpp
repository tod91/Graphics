//
//  VertexArray.cpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "GLError.h"

 
VertexArray::VertexArray()

{
    GLCall(glGenVertexArrays(1, &VAO_ID));
    Bind();
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &VAO_ID));
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(VAO_ID));
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned long size = elements.size();
    unsigned int offset = 0;
    for(GLuint i = 0; i < size; ++i)
    {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
        
        offset += element.count * VertexBufferElement::GetSizeType(element.type);
    }
    

}