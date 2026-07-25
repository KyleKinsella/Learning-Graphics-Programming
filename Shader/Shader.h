#pragma once

#include <string>
#include <unordered_map>

#include "../vendor/glm/glm.hpp"

class Shader {
public:
	Shader(const std::string& filePath1, const std::string& filePath2);
	~Shader();
	
	void bind() const;
	void unBind() const;
	
	// set-up our uniforms
	void setUniform1i(const std::string& name, int value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
	unsigned int m_RendererId;
	std::string m_filePath1;
	std::string m_filePath2;
	
	// caching for uniforms
	std::unordered_map<std::string, int> m_UniformLocationCache;
		
	std::string readShaderFile(const std::string& filePath);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	int getUniformLocation(const std::string& name);
};
