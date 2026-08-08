#include "Shader.h"

#include <fstream>
#include <iostream>
#include <vector>

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader) {
	std::string vs = readShaderFile(vertexShader);
	std::string fs = readShaderFile(fragmentShader);
	
	m_RenderId = createShader(vs, fs);
}

Shader::~Shader() {
	glDeleteProgram(m_RenderId);
}

void Shader::bind() const {
	glUseProgram(m_RenderId);
}

void Shader::unBind() const {
	glUseProgram(0);
}

unsigned int Shader::compileShader(unsigned int typeOfShader, const std::string& glslSourceCode) {
	unsigned int type = glCreateShader(typeOfShader);
	const char* src = glslSourceCode.c_str();
	glShaderSource(type, 1, &src, nullptr);
	glCompileShader(type);
	
	// now i need to check to see if i have any form of compiling errors for either of my shaders...
	int didShaderCompile;
	glGetShaderiv(type, GL_COMPILE_STATUS, &didShaderCompile);
	if (!didShaderCompile) {
		// i was not sure what to do here, so, i used the code in the docs.gl example.
		int size = 0;		
		char msg[1024];
		
		glGetShaderInfoLog(type, 1024, &size, msg); 
		
		//std::cout << "An error has occured while trying to compile your " << (typeOfShader == GL_VERTEX_SHADER) ? "Vertex Shader." : "Fragment Shader.";// << std::endl;
		std::cout << msg << std::endl;
	
		//~ return 1;
		
		return 0;
	}
	
	//~ glUseProgram(type);
	return type;
}

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	
	glLinkProgram(program);
	
	glValidateProgram(program);
	
	glDeleteShader(vs);
	glDeleteShader(fs);
	
	return program;
}

std::string Shader::readShaderFile(const std::string& fileName) {
	if (fileName == "") {
		return "You cannot read a file, if the file is empty!";
	}
	
	std::ifstream file(fileName);
	
	if (!file.is_open()) {
		std::cerr << "Could not open file called '" << fileName << "'." << std::endl;
		return "error...";
	}
	
	std::string content;
	std::string shaderSource;
	while (std::getline(file, content)) {
		shaderSource += content + "\n";
	}
	
	file.close();	
	return shaderSource;
}

int Shader::getUniformName(const std::string& uniformName) {
	int loc = glGetUniformLocation(m_RenderId, uniformName.c_str());
	
	if (loc == -1) {
		std::cout << "Warning: uniform '" << uniformName << "' doesn't exist!" << std::endl;
	} 
	
	return loc;
}

void Shader::sendUniformValue(const std::string& uniformName, glm::vec3 vec) {	
	glUniform3f(getUniformName(uniformName), vec.x, vec.y, vec.z);
}
