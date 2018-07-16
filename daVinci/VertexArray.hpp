//
//  VertexArray.hpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "ExportDefine.h"

class VertexBuffer;
class VertexBufferLayout;

class EXPORT VertexArray
{
public:
    VertexArray();
    ~VertexArray();
    
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void Bind() const;
    void Unbind() const;
    
private:
    unsigned int VAO_ID;
};

#endif /* VertexArray_hpp */
