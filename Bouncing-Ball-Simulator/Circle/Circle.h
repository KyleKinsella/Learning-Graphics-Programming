#pragma once

//~ #include <string> // leave for now, will probably need it in the near future

//~ #include "../Color/Color.h"
#include "../vendors/glm/glm.hpp"

// a circle will also have a thickness and a fade - in the future!
// i will also have a vector of multiple circles... so i can iterate over each circle...

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
