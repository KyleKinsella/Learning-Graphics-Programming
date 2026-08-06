#pragma once

//~ #include <string> // leave for now, will probably need it in the near future

#include "../Color/Color.h"

class Circle {
	public:
		Circle(int origin, int radius, int velocity, glm::vec3 color); 
		~Circle();
		
	private:
		//~ std::string circleName; // leave for now
		//~ int circleId; // leave for now
		int m_origin, m_radius, m_velocity;
		glm::vec3 m_color; //~ Color m_color;
};
