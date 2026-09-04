#include "Circle.h"

Circle::Circle(float lowerEdge, float higherEdge, float xCoord, float yCoord, glm::vec3 color) {
	m_lowerEdge = lowerEdge;
	m_higherEdge = higherEdge;
	m_xCoord = xCoord;
	m_yCoord = yCoord;
	m_color = color;
}

Circle::~Circle() {
}

float Circle::updateBallsYCoordinate(Circle circle, float newYValue, float timeElapsed) {
	// a ball is zero, so give him a value so he can move
	if (newYValue == 0) 
		newYValue = 2.0;
			
	return circle.m_yCoord += sin(timeElapsed * newYValue) * 100.0;
}

float Circle::dropBall(float result, float end) {
	for (int i = 0; i < result - end; i++) {
		result -= 1.0;
	}	
	return result;
}
