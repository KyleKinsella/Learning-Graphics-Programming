#pragma once

#include <string>

#include "../glad/include/glad/glad.h"
#include "../vendors/glm/glm.hpp"

class Shader {
public:
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();
	
	void bind() const;
	void unBind() const;
	
	unsigned int compileShader(unsigned int typeOfShader, const std::string& glslSourceCode);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	std::string readShaderFile(const std::string& fileName);
	
	// Uniforms
	int getUniformName(const std::string& uniformName);
	void sendUniformValue(const std::string& uniformName, glm::vec3 vec);
	void createNBalls(const std::string& uniformName, float v0);
	
private:
	unsigned int m_RenderId;
};
