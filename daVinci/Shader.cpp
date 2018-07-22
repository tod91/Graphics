//
//  Shader.cpp
//  daVinci
//
//  Created by Todor Ivanov on 5/11/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#include "Shader.hpp"
#include "GLError.h"
// This sucks find a better use for rp malloc. in oredr to get the gainz i would need alot of rly small allocations
#include "rpmalloc.h"
#include <stdio.h>

static unsigned long GetFileSize(FILE* file)
{
    unsigned long size;
    fseek (file , 0 , SEEK_END);
    size = ftell (file);
    rewind (file);
    return size;
}

Shader::Shader(const char* vShaderPath, const char* fShaderPath)
{
    vShaderFilePath = vShaderPath;
    fShaderFilePath = fShaderPath;
    
    rpmalloc_initialize();
}

Shader::~Shader()
{
    rpfree(vShaderSource);
    rpfree(fShaderSource);
}

bool Shader::GetShaderSource()
{
    FILE* vShaderFile = fopen(vShaderFilePath.c_str(), "rb");
    if(!vShaderFile)
    {
        fprintf(stderr, "Error, cannot open file %s\n", vShaderFilePath.c_str());
        return false;
    }

    FILE* fShaderFile = fopen(fShaderFilePath.c_str(), "rb");
    if(!fShaderFile)
    {
        fprintf(stderr, "Error, cannot open file %s\n", fShaderFilePath.c_str());
        return false;
    }

    unsigned long vfileSize = GetFileSize(vShaderFile);
    unsigned long ffileSize = GetFileSize(fShaderFile);

    vShaderSource = (char*) rpmalloc(vfileSize);
    fShaderSource = (char*) rpmalloc(ffileSize);

    //TODO: add some error check
    fread(vShaderSource, 1, vfileSize, vShaderFile);
    fread(fShaderSource, 1, ffileSize, fShaderFile);

    fclose(vShaderFile);
    fclose(vShaderFile);

    return true;
}

bool Shader::CompileShader()
{
    int success;
    char infoLog[512];

    m_vertexID = glCreateShader(GL_VERTEX_SHADER);
    GLCall(glShaderSource(m_vertexID, 1, &vShaderSource, NULL));

    GLCall(glCompileShader(m_vertexID));
    glGetShaderiv(m_vertexID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(m_vertexID, 512, NULL, infoLog);
        puts("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        printf("%s", infoLog);

        return false;
    };

    m_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    GLCall(glShaderSource(m_fragmentID, 1, &fShaderSource, NULL));

    GLCall(glCompileShader(m_fragmentID));
    glGetShaderiv(m_fragmentID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(m_vertexID, 512, NULL, infoLog);
        puts("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        printf("%s", infoLog);

        return false;
    };

    return true;
}

bool Shader::LinkShader()
{
    m_ShaderProgramID = glCreateProgram();
    glAttachShader(m_ShaderProgramID, m_vertexID);
    glAttachShader(m_ShaderProgramID, m_fragmentID);
    glLinkProgram(m_ShaderProgramID);

    int success;
    char infoLog[512];

    glGetProgramiv(m_ShaderProgramID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_ShaderProgramID, 512, NULL, infoLog);
        puts("ERROR::SHADER::PROGRAM::LINKING_FAILED");
        printf("%s", infoLog);

        // think about whether u need to delete the shaders before returning false
        return false;
    }

    glDeleteShader(m_vertexID);
    glDeleteShader(m_fragmentID);
    return true;
}

bool Shader::BuildShaderProgram()
{
    GetShaderSource();
    if(!CompileShader())
        return false;
    if(!LinkShader())
        return false;

    return true;
}

void Shader::SetUniform4f(const std::string name, const float v1, const float v2, const float v3, const float v4)
{
    GLCall(glUniform4f(GetUniformLocation(name), v1, v2, v3, v4));
}

int Shader::GetUniformLocation(const std::string& name)
{
    GLCall(int location = glGetUniformLocation(m_ShaderProgramID, name.c_str()));
    if(location == -1)
        printf("Warning: uniform %s doesnt exist", name.c_str());

    return location;
}

void Shader::Bind() const
{
    glUseProgram(m_ShaderProgramID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}
