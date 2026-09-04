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
	void updateABall(Shader& shader, const char* title);
	void useMVP(Shader& shader);
	void init(Shader& shader, const char* title1, const char* title2);
	void drawImGuiToScreen();
	
private:
	bool m_active_texture = false;
	bool m_active_mvp = true;
	bool m_update_ball = false;
	
	int m_ballToUpdate;
	glm::vec3 m_a;	
	
	float m_loweredge_and_higheredge[2];
	float m_xcoord_and_ycoord[2];
	float m_ball_color[3];
	
	float m_update_lower_and_higher[2];
	float m_update_x_and_y[2];
	float m_update_color[3];
};
