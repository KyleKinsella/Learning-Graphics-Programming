#pragma once

#include "../../vendors/glm/gtc/matrix_transform.hpp"
#include "../../Everyone/all.h"
#include "../../Everyone/some.h"

class MVP {
public:
	MVP();
	~MVP();
	
	glm::mat4 computeMvpMatrix(glm::mat4& model);
		
private:
	glm::mat4 m_proj, m_view;
};
