#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Shader.h"
#include "../Renderer/renderer.h"

Shader::Shader(const std::string& filePath1, const std::string& filePath2) : m_filePath1(filePath1), m_filePath2(filePath2), m_RendererId(0) {
	std::string vs = readShaderFile(filePath1);
	std::string fs = readShaderFile(filePath2);
	
	m_RendererId = createShader(vs, fs);
}

Shader::~Shader() {
	glCall(glDeleteProgram(m_RendererId));
}

std::string Shader::readShaderFile(const std::string& filePath) {
	std::ifstream file(filePath);
	
	std::string str;
	std::string content;
	while (std::getline(file, str)) {
		content.append(str + "\n");
	}
	
	return content;
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	
	// do we have a compiling error for either of our shaders ?
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		
		glGetShaderInfoLog(id, length, &length, message);
		
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message << std::endl;
		
		glDeleteShader(id);
		
		return 0;
	}
	
	return id;
}

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glCall(glAttachShader(program, vs));
	glCall(glAttachShader(program, fs));
	
	glCall(glLinkProgram(program));
	
	glCall(glValidateProgram(program));
	
	glCall(glDeleteShader(vs));
	glCall(glDeleteShader(fs));
	
	return program;
}

void Shader::bind() const {
	glCall(glUseProgram(m_RendererId));
}

void Shader::unBind() const {
	glCall(glUseProgram(0));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
	glCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

unsigned int Shader::getUniformLocation(const std::string& name) {
	
	//~ if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
		//~ return m_UniformLocationCache[name];
	//~ }
	
	glCall(unsigned int location = glGetUniformLocation(m_RendererId, name.c_str()));
	if (location == -1) {
		std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
	} 
	
	//~ m_UniformLocationCache[name] = location;
		
	return location;
}
