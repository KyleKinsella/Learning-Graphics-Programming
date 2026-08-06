#include "Shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader) : m_fileName1(vertexShader), m_fileName2(fragmentShader) {
	std::string vs = readShaderFile(vertexShader);
	std::string fs = readShaderFile(fragmentShader);
	
	// TODO: process the vertex shader and fragment shader...
	std::cout << vs << "\n\n" << fs << std::endl;
}

Shader::~Shader() {
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
