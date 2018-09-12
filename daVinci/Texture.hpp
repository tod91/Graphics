//
//  Texture.hpp
//  daVinci
//
//  Created by Todor Ivanov on 7/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp
#include <string>
#include "ExportDefine.h"

class EXPORT Texture
{
public:
    Texture(const std::string& path);
    ~Texture();
    
    void Bind(unsigned slot = 0) const;
    void Unbind() const;
    
private:
    std::string m_FilePath;
    unsigned m_TextureID;
    unsigned char* m_TextureBuffer;
    int m_Width, m_Height;
    int m_BPP;
    
};

#endif /* Texture_hpp */
