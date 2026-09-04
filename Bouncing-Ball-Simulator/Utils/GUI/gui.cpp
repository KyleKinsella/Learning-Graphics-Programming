#include "gui.h"

Gui::Gui(GLFWwindow* window) : m_a(200, 200, 0), m_one{0.0f, 0.0f}, m_two{0.0f, 0.0f}, m_color{0.10f, 0.20f, 0.30f } {
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	ImGui::StyleColorsDark();
}

Gui::~Gui() {
	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::setImGuiStyle(float fontSize) {
	ImGuiStyle& style = ImGui::GetStyle();
	style.FontSizeBase = fontSize;
}

void Gui::initImGuiEveryFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Gui::makeABall(const char* title) {
	ImGui::Text(title);
	
	ImGui::InputFloat2("lowerEdge, higherEdge", m_one);
	ImGui::InputFloat2("xCoord, yCoord", m_two);
	ImGui::InputFloat3("color", m_color);
				
	if (ImGui::Button("Load Textures")) {
		m_active_texture = true;
	}
	
	if (ImGui::Button("Hide Textures")) {
		m_active_texture = false;
	}
	ImGui::Text("\n");
}

Texture* Gui::initTexture() {
	Utils* utils;
	Texture* texture = nullptr;
	if (m_active_texture) {
		const std::vector<std::string> files = utils->getTextures("resources/textures/");
		for (int i = 0; i < files.size(); i++) {
			if (ImGui::Button(files[i].c_str())) {
				delete texture;
				texture = new Texture(files[i]);
				break;
			}
		}
		ImGui::Text("\n");
	}
	return texture;
}

void Gui::sendUniforms(Shader& shader) {
	glUniform1f(shader.getUniformName("lowerEdge"), m_one[0]);
	glUniform1f(shader.getUniformName("higherEdge"), m_one[1]);
	
	glUniform1f(shader.getUniformName("xCoord"), m_two[0]);
	glUniform1f(shader.getUniformName("yCoord"), m_two[1]);
	
	if (ImGui::Button("Create Ball with Texture")) {
		glUniform1i(shader.getUniformName("u_bool"), 0);
		glUniform1i(shader.getUniformName("u_Texture"), 0);
	}
	
	if (ImGui::Button("Create Ball with Color")) {
		glUniform1i(shader.getUniformName("u_bool"), 1);
		glUniform3f(shader.getUniformName("color"), m_color[0], m_color[1], m_color[2]);
	}
}

void Gui::updateABall(Shader& shader) {
	ImGui::Text("\n\nUpdate a Balls Attributes\n");
		
	if (ImGui::Button("Do you want to Update a Ball ?")) {
		m_update_ball = true;
	}
	
	if (ImGui::Button("Do you want to Hide the Update Ball Stuff ?")) {
		m_update_ball = false;
	}
	ImGui::Text("\n");
	
	if (m_update_ball) {
		static int ballToUpdate = 0;
		ImGui::InputInt("ballToUpdate", &ballToUpdate);
		
		static float lh[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("lower, higher", lh);
		
		static float xy[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("x, y", xy);
		
		static float u_color[3] = { 0.0f, 0.0f, 0.0f };
		ImGui::InputFloat3("u_color", u_color);
		
		ImGui::Text("\n");
			
		if (ImGui::Button("Update Ball")) {
			glUniform1i(shader.getUniformName("BALL_TO_UPDATE"), ballToUpdate);
			
			glUniform1f(shader.getUniformName("updateLowerEdge"), lh[0]);
			glUniform1f(shader.getUniformName("updateHigherEdge"), lh[1]);
			
			glUniform1f(shader.getUniformName("updateXCoord"), xy[0]);
			glUniform1f(shader.getUniformName("updateYCoord"), xy[1]);
			
			glUniform3f(shader.getUniformName("updateColor"), u_color[0], u_color[1], u_color[2]);	
		}
	}
	ImGui::Text("\n");
}

void Gui::useMVP(Shader& shader) {
	if (ImGui::Button("Enable MVP")) {
		m_active_mvp = true;
	}
	
	if (ImGui::Button("Disable MVP")) {
		m_active_mvp = false;
	}
	
	if (m_active_mvp) {
		MVP mvp;
		
		glm::mat4 modelA = glm::translate(glm::mat4(1.0f), m_a);
		glm::mat4 matrix = mvp.computeMvpMatrix(modelA);
		
		glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &matrix[0][0]);
		
		ImGui::Text("\nMVP Matrix");
		ImGui::SliderFloat2("Texture 1", &m_a.x, 0.0f, 960.0f);
	}
}

void Gui::init(Shader& shader, const char* title) {
	makeABall(title);
	
	Texture* texture = initTexture();
	if (texture) {
		texture->bindTexture();
	}
	
	sendUniforms(shader);
	updateABall(shader);
	
	shader.bind();
	
	useMVP(shader);
}

void Gui::drawImGuiToScreen() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
