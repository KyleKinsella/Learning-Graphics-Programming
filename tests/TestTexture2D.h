#pragma once

#include "Test.h"

#include "../Renderer/renderer.h"
#include "../VertexBufferLayout/VertexBufferLayout.h"
#include "../Textures/Texture.h"

#include <memory>

#include "../vendors/glm/glm.hpp"
#include "../vendors/glm/gtc/matrix_transform.hpp"
#include "../vendors/imgui/imgui.h"

namespace test {
	class TestTexture2D : public Test {
		public:
			TestTexture2D();
			~TestTexture2D();
			
			void onUpdate(float deltaTime) override;
			void onRender() override;
			void onImGuiRender() override;
			
		private: 
			std::unique_ptr<VertexArray> m_VAO;
			std::unique_ptr<VertexBuffer> m_VertexBuffer;
			std::unique_ptr<IndexBuffer> m_IndexBuffer;
			std::unique_ptr<Shader> m_Shader;
			std::unique_ptr<Texture> m_Texture;
			
			glm::mat4 m_proj, m_view;
			glm::vec3 m_TranslationA, m_TranslationB;
	};
}
