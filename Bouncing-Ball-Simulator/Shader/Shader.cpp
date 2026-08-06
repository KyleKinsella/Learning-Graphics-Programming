#include "Shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader) : m_fileName1(vertexShader), m_fileName2(fragmentShader) {
	std::string vs = readShaderFile(vertexShader);
	std::string fs = readShaderFile(fragmentShader);
	
	// TODO: process the vertex shader and fragment shader...
	std::cout << vs << "\n\n" << fs << std::endl;
	
	//~ m_RenderId = compileShader()
	m_RenderId = createShader(vs, fs);
	
	//~ m_renderId1 = 
	
	//~ createShader(GL_VERTEX_SHADER);
	//~ createShader(GL_FRAGMENT_SHADER);
}

Shader::~Shader() {
	//~ glDeleteProgram(m_RenderId);
}

//~ void Shader::bind() const {
	//~ glUseProgram(m_RenderId);
//~ }

//~ void Shader::unBind() const {
	//~ glUseProgram(0);
//~ }

unsigned int Shader::compileShader(unsigned int typeOfShader, const std::string& glslSourceCode) {
	unsigned int type = glCreateShader(typeOfShader);
	
	//~ glShaderSource(type, 1, glslSourceCode, NULL);
	//~ glCompileShader(type);
	
	const char* src = glslSourceCode.c_str();
	glShaderSource(type, 1, &src, nullptr);
	glCompileShader(type);
	
	// now i need to check to see if i have any form of compiling errors for either of my shaders...
	int didShaderCompile;
	glGetShaderiv(type, GL_COMPILE_STATUS, &didShaderCompile);
	if (!didShaderCompile) {
		// i was not sure what to do here, so, i used the code in the docs.gl example.
		int size = 0;
		//~ const char* msg[1024];
		
		char msg[1024];
		
		glGetShaderInfoLog(type, 1024, &size, msg); 
		
		//std::cout << "An error has occured while trying to compile your " << (typeOfShader == GL_VERTEX_SHADER) ? "Vertex Shader." : "Fragment Shader.";// << std::endl;
		std::cout << msg << std::endl;
	
		return 1;
	}
	
	glUseProgram(type);
	return type;
}

//~ unsigned int typeOfShader
//~ const std::string& glslSourceCode
unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
	//~ unsigned int program = glUseProgram();
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
	
	//~ glDeleteProgram(program);
	
	
	
	//~ compileShader()
	
	
	
	
	
	
	//~ glAttachShader(program, typeOfShader);
	
	//~ glLinkProgram(program);
	
	//~ glValidateProgram(program);
	
	//~ glDeleteProgram(program);
	
	//~ unsigned int shaderId = compileShader(typeOfShader, glslSourceCode);	
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
