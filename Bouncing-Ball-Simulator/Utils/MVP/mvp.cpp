#include "mvp.h"

MVP::MVP() : m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)), m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))) {
}

MVP::~MVP() {
}

//~ Shader shader, Texture* texture, 
glm::mat4 MVP::computeMvpMatrix(glm::mat4& model) {
	//~ texture->bindTexture();
	
	//~ glm::mat4 mvp = m_proj * m_view * model;
	
	return m_proj * m_view * model;
	
	//~ shader.bind();

	//~ glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &mvp[0][0]);
}
