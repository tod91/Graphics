//
//  Texture.cpp
//  daVinci
//
//  Created by Todor Ivanov on 7/24/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "Texture.hpp"
#include "GLError.h"
#include "stb_image.h"

Texture::Texture(const std::string& path)
: m_FilePath(path)
, m_TextureID(0)
, m_TextureBuffer(nullptr)
, m_Width(0)
, m_Height(0)
, m_BPP(0)
{
    stbi_set_flip_vertically_on_load(true);
    m_TextureBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
    
    GLCall(glGenTextures(1, &m_TextureID));
    Bind();
    
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_TextureBuffer));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    Unbind();
    
    if(m_TextureBuffer)
        stbi_image_free(m_TextureBuffer);
    
}

Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &m_TextureID));
}

void Texture::Bind(unsigned slot) const
{
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    glBindTexture(GL_TEXTURE_2D, slot);
}


void Texture::Unbind() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
