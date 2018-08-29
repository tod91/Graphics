//
//  Shader.hpp
//  daVinci
//
//  Created by Todor Ivanov on 5/11/18.
//  Copyright © 2018 Todor Ivanov. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "ExportDefine.h"
#include <string>

class EXPORT Shader
{
public:
    Shader(const char* vShaderPath, const char* fShaderPath);
    ~Shader();
    
    void Bind() const;
    void Unbind() const;
    
    bool BuildShaderProgram();
    void SetUniform4f(const std::string name, float v1, float v2, float v3, float v4);
    void SetUniform1i(const std::string name, int v1);
    
private: // METHODS
    bool     GetShaderSource();
    bool     CompileShader();
    bool     LinkShader();
    int GetUniformLocation(const std::string& name);
    
private: // DATA
    char* vShaderSource;
    char* fShaderSource;
    std::string vShaderFilePath;
    std::string fShaderFilePath;
    
    unsigned    m_vertexID;
    unsigned    m_fragmentID;
    unsigned    m_ShaderProgramID;
};
#endif /* Shader_hpp */
