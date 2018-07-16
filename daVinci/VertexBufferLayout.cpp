//
//  VertexBufferLayout.cpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "VertexBufferLayout.hpp"

VertexBufferLayout::VertexBufferLayout()
{
    
}

VertexBufferLayout::~VertexBufferLayout()
{
    
}

void VertexBufferLayout::Push(GLNumber num, int count, bool normalized)
{
    switch (num)
    {
        case FLOAT:
            m_Elements.push_back({ GL_FLOAT, count, normalized });
            m_Stride += count * VertexBufferElement::GetSizeType(GL_FLOAT);
            break;
            
        case U_BYTE:
            m_Elements.push_back({ GL_UNSIGNED_BYTE, count, normalized });
            m_Stride += count * VertexBufferElement::GetSizeType(GL_UNSIGNED_BYTE);
            break;
            
        case U_INT:
            m_Elements.push_back({ GL_UNSIGNED_INT, count, normalized });
            m_Stride += count * VertexBufferElement::GetSizeType(GL_UNSIGNED_INT);
            break;
            
        default:
            ASSERT(false);
            break;
    }
}