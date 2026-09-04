#pragma once

#include "../vendors/glm/glm.hpp"

class Circle {
public:
	Circle(float lowerEdge, float higherEdge, float xCoord, float yCoord, glm::vec3 color);
	~Circle();

	float updateBallsYCoordinate(Circle circle, float newYValue, float timeElapsed);
	float dropBall(float result, float end);
	
	float m_lowerEdge, m_higherEdge, m_xCoord, m_yCoord;
	glm::vec3 m_color;			
private:
};
