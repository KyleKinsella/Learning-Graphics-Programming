#include "gui.h"

Gui::Gui(GLFWwindow* window) : m_a(200, 200, 0), m_loweredge_and_higheredge{0.0f, 0.0f}, m_xcoord_and_ycoord{0.0f, 0.0f}, m_ball_color{0.10f, 0.20f, 0.30f}, m_update_lower_and_higher{0.0f, 0.0f}, m_update_x_and_y{0.0f, 0.0f}, m_update_color{0.0f, 0.0f, 0.0f}, m_ballToUpdate(0) {
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
	
	ImGui::InputFloat2("lowerEdge, higherEdge", m_loweredge_and_higheredge);
	ImGui::InputFloat2("xCoord, yCoord", m_xcoord_and_ycoord);
	ImGui::InputFloat3("color", m_ball_color);
	
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
	glUniform1f(shader.getUniformName("lowerEdge"), m_loweredge_and_higheredge[0]);
	glUniform1f(shader.getUniformName("higherEdge"), m_loweredge_and_higheredge[1]);
	
	glUniform1f(shader.getUniformName("xCoord"), m_xcoord_and_ycoord[0]);
	glUniform1f(shader.getUniformName("yCoord"), m_xcoord_and_ycoord[1]);
	
	if (ImGui::Button("Create Ball with Texture")) {
		glUniform1i(shader.getUniformName("u_bool"), 0);
		glUniform1i(shader.getUniformName("u_Texture"), 0);
	}
	
	if (ImGui::Button("Create Ball with Color")) {
		glUniform1i(shader.getUniformName("u_bool"), 1);
		glUniform3f(shader.getUniformName("color"), m_ball_color[0], m_ball_color[1], m_ball_color[2]);
	}
}

void Gui::updateABall(Shader& shader, const char* title) {
	ImGui::Text(title);
		
	if (ImGui::Button("Do you want to Update a Ball ?")) {
		m_update_ball = true;
	}
	
	if (ImGui::Button("Do you want to Hide the Update Ball Stuff ?")) {
		m_update_ball = false;
	}
	ImGui::Text("\n");
	
	if (m_update_ball) {
		ImGui::InputInt("ballToUpdate", &m_ballToUpdate);
		ImGui::InputFloat2("lower, higher", m_update_lower_and_higher);
		ImGui::InputFloat2("x, y", m_update_x_and_y);		
		ImGui::InputFloat3("u_color", m_update_color);
		
		ImGui::Text("\n");
		
		if (ImGui::Button("Update Ball")) {
			glUniform1i(shader.getUniformName("BALL_TO_UPDATE"), m_ballToUpdate);
			
			glUniform1f(shader.getUniformName("updateLowerEdge"), m_update_lower_and_higher[0]);
			glUniform1f(shader.getUniformName("updateHigherEdge"), m_update_lower_and_higher[1]);
			
			glUniform1f(shader.getUniformName("updateXCoord"), m_update_x_and_y[0]);
			glUniform1f(shader.getUniformName("updateYCoord"), m_update_x_and_y[1]);
			
			glUniform3f(shader.getUniformName("updateColor"), m_update_color[0], m_update_color[1], m_update_color[2]);	
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

void Gui::init(Shader& shader, const char* title1, const char* title2) {
	makeABall(title1);
	
	Texture* texture = initTexture();
	if (texture) {
		texture->bindTexture();
	}
	
	sendUniforms(shader);
	updateABall(shader, title2);
	
	shader.bind();
	
	useMVP(shader);
}

void Gui::drawImGuiToScreen() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
