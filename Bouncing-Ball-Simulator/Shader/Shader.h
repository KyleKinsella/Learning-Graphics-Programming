#pragma once

#include <string>

#include "../glad/include/glad/glad.h"

class Shader {
public:
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();
	
	//~ void bind() const;
	//~ void unBind() const;
	
	unsigned int compileShader(unsigned int typeOfShader, const std::string& glslSourceCode);
	
	//~ const std::string& glslSourceCode
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	std::string readShaderFile(const std::string& fileName);

private:
	std::string m_fileName1;
	std::string m_fileName2;
	
	//~ unsigned int m_renderId1;
	//~ unsigned int m_renderId2;
	
	unsigned int m_RenderId;
	
};
