#version 330 core

layout (location = 0) out vec4 color;

#define UV gl_FragCoord.xy
#define BALLS 5

struct Ball {
	float lowerEdge;
	float higherEdge;
	float xCoord;
	float yCoord;
	vec3 color;
};

// TODO: add color...
float createCircle(float lowerEdge, float higherEdge, float xCoord, float yCoord) {
	return 1.0 - smoothstep(lowerEdge, higherEdge, distance(UV, vec2(xCoord, yCoord)));
}

float createCircleAndBall(Ball ball) {
	return 1.0 - smoothstep(ball.lowerEdge, ball.higherEdge, distance(UV, vec2(ball.xCoord, ball.yCoord)));
}

void main() {
	float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	float purpleCircle = createCircle(2.0, 5.0, 640.0, 320.0);
	float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
		
	vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(0.65, 0.56, 1.0) * purpleCircle + vec3(1.0, 0.55, 0.76) * pinkCircle;
	
	Ball balls[BALLS];
	for (int i = 0; i < balls.length(); i++) {
		balls[i].lowerEdge = 12.0;
		balls[i].higherEdge = 25.0;
		balls[i].xCoord = 100.0 + float(i) * 130.0;
		balls[i].yCoord = 200.0;
		balls[i].color = vec3(1.0, 0.0, 0.0);
	}
	
	for (int i = 0; i < BALLS; i++) {
		float circle = createCircleAndBall(balls[i]);
		canvas += circle * balls[i].color;
	}
	
	color = vec4(canvas, 1.0);
}
