#include "TestTexture2D.h"

namespace test {
	TestTexture2D::TestTexture2D() : m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)), m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))), m_TranslationA(200, 200, 0), m_TranslationB(400, 200, 0) {
				
		float vertexBuffer[] = {
			-450.0f, -450.0f, 0.0f, 0.0f, // 0
			300.0f, -450.0f, 1.0f, 0.0f, // 1
			300.0f, 300.0f, 1.0f, 1.0f, // 2
			-450.0f, 300.0f, 0.0f, 1.0f // 3
		};
		
		unsigned int indexBuffer[] = {
			0, 1, 2,
			2, 3, 0
		};
	
		// blending
		glCall(glEnable(GL_BLEND));
		glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		
		m_VAO = std::make_unique<VertexArray>();
		
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertexBuffer, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);

		m_VAO->addBuffer(*m_VertexBuffer, layout);
		
		m_IndexBuffer = std::make_unique<IndexBuffer>(indexBuffer, 6);
		
		const std::string vs = "../res/shaders/vertexShader.shader";
		const std::string fs = "../res/shaders/fragmentShader.shader";
		m_Shader = std::make_unique<Shader>(vs, fs);
		
		m_Shader->bind();
		//~ m_Shader->setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
		
		m_Texture = std::make_unique<Texture>("../res/textures/sekiro.png");
		m_Shader->setUniform1i("u_Texture", 0);
	}
	
	TestTexture2D::~TestTexture2D() {
	}
	
	void TestTexture2D::onUpdate(float deltaTime) {
	}
	
	void TestTexture2D::onRender() {
		glCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		glCall(glClear(GL_COLOR_BUFFER_BIT));
		
		glm::mat4 modelA = glm::translate(glm::mat4(1.0f), m_TranslationA);
		viewTexture(modelA);
		
		glm::mat4 modelB = glm::translate(glm::mat4(1.0f), m_TranslationB);	
		viewTexture(modelB);
	}
	
	void TestTexture2D::onImGuiRender() {
		ImGui::SliderFloat3("Translation A", &m_TranslationA.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B", &m_TranslationB.x, 0.0f, 960.0f);
	}
	
	void TestTexture2D::viewTexture(glm::mat4 model) {
		Renderer renderer;
		m_Texture->bind();
		
		glm::mat4 mvp = m_proj * m_view * model; // the multiplication goes from right to left
			
		m_Shader->bind();
			
		m_Shader->setUniformMat4f("u_MVP", mvp);	
		renderer.draw(*m_VAO, *m_IndexBuffer, *m_Shader);
	}
}
