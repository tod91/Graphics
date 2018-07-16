//#include "glfw3.h"
#include <vector>
#include <string>
#include <OpenGL/gl3.h>

class Window;
class Shader;
class VertexBuffer;
class VertexArray;
class IndexBuffer;
class GLFWwindow;
struct VertexBufferElement;


enum GLNumber
{
    FLOAT = GL_FLOAT, U_BYTE = GL_UNSIGNED_BYTE, U_INT = GL_UNSIGNED_INT
};

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    void Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader, GLFWwindow*);
};

class VertexBufferLayout
{
public:
    VertexBufferLayout();
    ~VertexBufferLayout();
    
    void     Push(GLNumber num, int count, bool normalized);
    int GetStride() const;
    
    //Optimize this with a move.
    const std::vector<VertexBufferElement> GetElements() const;
    
private:
    std::vector<VertexBufferElement> m_Elements;
    int m_Stride;
    
};

class VertexArray
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

class IndexBuffer
{
public:
    // In the future think of a way to get 16 bit integer support
    // HINT look at int_fast16_t
    IndexBuffer(const unsigned* data, const unsigned count);
    ~IndexBuffer();
    
    void Bind() const;
    void Unbind() const;
    
    unsigned int GetCount() const;
private:
    unsigned mIndices_ID;
    unsigned mCount;
};

class  VertexBuffer
{
public:
    VertexBuffer(const void* data, const unsigned size);
    ~VertexBuffer();
    
    void Bind() const;
    void Unbind() const;
private:
    unsigned mVBO_ID;
};

class Shader
{
public:
    Shader(const char* vShaderPath, const char* fShaderPath);
    Shader();
    ~Shader();
    
    void Bind() const;
    void Unbind() const;
    
    void AddShaders(const char* vShaderPath, const char* fShaderPath);
    bool BuildShaderProgram();
    
private: // METHODS
    bool     GetShaderSource();
    bool     CompileShader();
    bool     LinkShader();
    unsigned GetUniformLocation(const std::string& name);
    
private: // DATA
    char* vShaderSource;
    char* fShaderSource;
    std::string vShaderFilePath;
    std::string fShaderFilePath;
    
    unsigned    m_vertexID;
    unsigned    m_fragmentID;
    unsigned    m_ShaderProgramID;
};

class Window
{
public:
     Window();
    ~Window();
    
    bool createWindow(const unsigned short width, const unsigned short heigh, const char* title);
    GLFWwindow* getWindow() const;
    
private:
    GLFWwindow* window;
};
