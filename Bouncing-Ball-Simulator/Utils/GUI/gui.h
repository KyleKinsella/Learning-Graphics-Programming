#pragma once

#include "../../Everyone/all.h"
#include "../../Everyone/some.h"

#include "../../Textures/Texture.h"
#include "../../Utils/Utils/utils.h"
#include "../../Shader/Shader.h"
#include "../../Utils/MVP/mvp.h"

#include "../../vendors/glm/gtc/matrix_transform.hpp"

class Gui {
public:
	Gui(GLFWwindow* window);
	~Gui();
	
	void setImGuiStyle(float fontSize);
	void initImGuiEveryFrame();
	void makeABall(const char* title);
	Texture* initTexture();
	void sendUniforms(Shader& shader);
	void updateABall(Shader& shader);
	void useMVP(Shader& shader);
	void init(Shader& shader, const char* title);
	void drawImGuiToScreen();
	
private:
	bool m_active_texture = false;
	bool m_active_mvp = true;
	bool m_update_ball = false;
	
	glm::vec3 m_a;	
	
	float m_one[2];
	float m_two[2];
	float m_color[3];
};
