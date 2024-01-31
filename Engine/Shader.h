#pragma once
#include <string>
#include <unordered_map>
#include <glm.hpp>
#include "../include/glad/glad.h"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& filepath);
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);

	~Shader();

	void Activate() const;

	void Bind() const;
	void Unbind() const;

	// set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
	void Set3Float(const std::string& name, float value);


	// set vertex attrib pointers
	void VertexAttribPointer(const std::string& name, int size, GLenum type, bool normalized, size_t stride, const void* offset);
private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);
};

