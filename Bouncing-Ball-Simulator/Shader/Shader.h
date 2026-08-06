#pragma once

#include <string>

class Shader {
public:
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();
	
	std::string readShaderFile(const std::string& fileName);

private:
	std::string m_fileName1;
	std::string m_fileName2;
};
