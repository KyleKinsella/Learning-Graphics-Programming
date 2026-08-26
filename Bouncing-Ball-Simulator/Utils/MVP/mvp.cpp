#include "mvp.h"

MVP::MVP() : m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)), m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))) {
}

MVP::~MVP() {
}

glm::mat4 MVP::computeMvpMatrix(glm::mat4& model) {
	return m_proj * m_view * model;
}

void MVP::mvpSlider() {
	//~ ImGui::SliderFloat2("Texture 1", &m_translation.x, 0.0f, 960.0f);
}
