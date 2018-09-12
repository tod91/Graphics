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
    Renderer(bool wireFrameMode = false);
    ~Renderer();
    
    void DrawArrays(const VertexArray& va, const Shader& shader, GLFWwindow* window, int size);
    void Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader, GLFWwindow* window);
};

class VertexBufferLayout
{
public:
    VertexBufferLayout();
    ~VertexBufferLayout();
    
    void     Push(GLNumber num, int count, bool normalized);
    int      GetStride() const;
    
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
    ~Shader();
    
    void Bind() const;
    void Unbind() const;
    
    bool BuildShaderProgram();
    void SetUniform4f(const std::string name, float v1, float v2, float v3, float v4);
    void SetUniform1i(const std::string name, int v1);
    
private:
    bool     GetShaderSource();
    bool     CompileShader();
    bool     LinkShader();
    int GetUniformLocation(const std::string& name);
    
private:
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

class Texture
{
public:
    Texture(const std::string& path, const bool hasAlpha = false, unsigned slot = 0);
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
