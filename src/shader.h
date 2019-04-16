
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class Shader {
private:
    unsigned int type_;
    std::string source_;

public:
    // Constructs a new shader with the given type and source code.
    Shader(unsigned int type, std::string &source);

    // Compiles this shader and returns its ID.
    unsigned int compile();

private:
    // Utility function for checking shader compilation/linking errors.
    static void checkCompileErrors(unsigned int id) {
        int success;
        char infoLog[1024];
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, 1024, nullptr, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION: " << "\n" << infoLog
                      << "-----------------------------------------------" << std::endl;
        }
    };
};

class ShaderProgram {
private:
    // The ID of this shader program.
    unsigned int id_;
    // The vertex and fragment shader code.
    std::string vertexSource_, fragmentSource_;

public:
    // Reads the shaders from the file path and set the shader sources.
    ShaderProgram(const std::string &filePath);

    void createProgram();

    void use();

    // Utility uniform functions.
    void setBool(const std::string &name, bool value);

    void setInt(const std::string &name, int value);

    void setFloat(const std::string &name, float value);

    inline unsigned int getId() { return id_; }
};

#endif
