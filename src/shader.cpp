#include "shader.h"

Shader::Shader(unsigned int type, std::string &source) {
    type_ = type;
    source_ = source;
}

unsigned int Shader::compile() {
    unsigned int id = glCreateShader(type_);
    const char *src = source_.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    checkCompileErrors(id);
    return id;
}

// Read the shaders from the file path and set the shader sources.
ShaderProgram::ShaderProgram(const std::string &filePath) {
    std::ifstream stream(filePath);
    if (stream.fail()) {
        std::cerr << "ERROR::SHADER_PROGRAM: Could not find shader " << filePath << "!" << std::endl;
    }

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    // Put current line of stream into line.
    while (getline(stream, line)) {
        // Search within line string.
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
            // ShaderParser specific code found.
        } else {
            ss[(int) type] << line << '\n';
        }
    }
    vertexSource_ = ss[(int) ShaderType::VERTEX].str();
    fragmentSource_ = ss[(int) ShaderType::FRAGMENT].str();
}

void ShaderProgram::createProgram() {

    id_ = glCreateProgram();
    unsigned int vs = Shader(GL_VERTEX_SHADER, vertexSource_).compile();
    unsigned int fs = Shader(GL_FRAGMENT_SHADER, fragmentSource_).compile();

    glAttachShader(id_, vs);
    glAttachShader(id_, fs);
    glLinkProgram(id_);
    glValidateProgram(id_);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void ShaderProgram::use() {
    glUseProgram(id_);
}

// Utility uniform functions.
void ShaderProgram::setBool(const std::string &name, bool value) {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int) value);
}

void ShaderProgram::setInt(const std::string &name, int value) {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}
