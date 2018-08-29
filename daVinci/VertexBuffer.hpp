//
//  VertexBuffer.hpp
//  daVinci
//
//  Created by Todor Ivanov on 5/13/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

#include "ExportDefine.h"

class EXPORT VertexBuffer
{
public:
    VertexBuffer(const void* data, const unsigned size);
    ~VertexBuffer();
    
    void Bind() const;
    void Unbind() const;
    
private:
    unsigned m_VBO_ID;
};

#endif /* VertexBuffer_hpp */
