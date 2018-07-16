//
//  IndexBuffer.hpp
//  daVinci
//
//  Created by Todor Ivanov on 5/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp

#include "ExportDefine.h"

class EXPORT IndexBuffer
{
public:
    // In the future think of a way to get 16 bit integer support
    // HINT look at int_fast16_t
    IndexBuffer(const unsigned* data, const unsigned count);
    ~IndexBuffer();
    
    void Bind() const;
    void Unbind() const;
    
    unsigned int GetCount() const { return mCount; }
private:
    unsigned mIndices_ID;
    unsigned mCount;
};
#endif /* IndexBuffer_hpp */
