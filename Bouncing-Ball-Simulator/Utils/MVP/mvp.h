#pragma once

#include "../../vendors/glm/gtc/matrix_transform.hpp"
#include "../../Everyone/all.h"
#include "../../Everyone/some.h"

//~ #include "../../Shader/Shader.h"
//~ #include "../../Textures/Texture.h"

class MVP {
public:
	MVP();
	~MVP();

	//~ void computeMvpMatrix(Shader shader, Texture* texture, glm::mat4& model);
	glm::mat4 computeMvpMatrix(glm::mat4& model);
		
private:
	glm::mat4 m_proj, m_view;
};
