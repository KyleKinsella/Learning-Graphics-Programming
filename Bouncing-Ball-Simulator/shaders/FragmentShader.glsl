#version 330 core

layout (location = 0) out vec4 color;

#define UV gl_FragCoord.xy
#define BALLS 5

uniform float time;

struct Ball {
	float lowerEdge, higherEdge, xCoord, yCoord;
	vec3 color;
};

// TODO: add color...
float createCircle(float lowerEdge, float higherEdge, float xCoord, float yCoord) {
	return 1.0 - smoothstep(lowerEdge, higherEdge, distance(UV, vec2(xCoord, yCoord)));
}

float createCircle(Ball ball) {
	return 1.0 - smoothstep(ball.lowerEdge, ball.higherEdge, distance(UV, vec2(ball.xCoord, ball.yCoord)));
}

//~ balls[i].yCoord += sin(time*2.0) * 100.0;
float updateBallsYCoordinate(Ball ball, float newYValue, float timeElapsed) {
	if (newYValue == 0) 
		newYValue = 2.0;
	return ball.yCoord += sin(timeElapsed * newYValue) * 100.0;
}

float dropBall(float result, float end) {
	for (int i = 0; i < result - end; i++) {
		result -= 1.0;
	}
	
	return result;
}

float test(Ball ball, float newYValue, float end) {
	int i = 0;
	float result = 0.0;

	while (true) {

	//~ while (i != timesToLoop) {
		//~ result = updateBallsYCoordinate(ball, newYValue);
		result = dropBall(result, end);
		
		//~ updateBallsYCoordinate(ball, newYValue) -= dropBall(result, end);
		//~ dropBall(result, end) += updateBallsYCoordinate(ball, newYValue);
		i++;
	}
	return result;
}

void main() {
	float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	float purpleCircle = createCircle(22.0, 25.0, 420.0, 350.0);
	//~ float purpleCircle = createCircle(22.0, 44.0, 640.0, 580.0);
	float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
	
	vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(0.65, 0.56, 1.0) * purpleCircle + vec3(1.0, 0.55, 0.76) * pinkCircle;
	//~ vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(1.0, 0.55, 0.76) * pinkCircle;
	
	//~ canvas = vec3(0.0);
	
	Ball balls[BALLS];
	for (int i = 0; i < balls.length(); i++) {
		balls[i].lowerEdge = 12.0;
		balls[i].higherEdge = 25.0;
		balls[i].xCoord = 100.0 + float(i) * 130.0;
		
		//~ balls[i].yCoord = 200.0 + sin(i) * 100.0;
		//~ balls[i].yCoord = 100.0 * sin(time * 2.0 * i) * 130.0;
		//~ balls[i].yCoord = 200.0 + sin(time*2.0) * 100.0;
		balls[i].yCoord = 200.0;

		//~ balls[i].yCoord = 500.0;
		
		balls[i].color = vec3(1.0, 0.0, 0.0);
		
		if (i == BALLS-1) {
			balls[i].color = vec3(0.0, 1.0, 0.0);
			
			//~ balls[i].yCoord += sin(time*2.0) * 100.0;
			
			//~ balls[i].yCoord += sin(time*2.0*i) * 100.0;
			
			//~ balls[i].yCoord += sin(time*2.0) * 100.0;
			
			//~ balls[i].yCoord += updateBallsYCoordinate(balls[i], i*69.0, time);
			
			balls[i].yCoord += updateBallsYCoordinate(balls[i], i*5.0, time);
		
			//~ balls[i].yCoord -= dropBall(balls[i].yCoord, 80.0);
			
			
			
			//~ balls[i].yCoord += updateBallsYCoordinate(balls[i], 150.0);
			
			//~ balls[i].yCoord -= dropBall(balls[i].yCoord, -450.0); // at the top of the window (or very close to it)
			//~ balls[i].yCoord -= dropBall(balls[i].yCoord, 350.0); // very close to the bottom of the window
			
			//~ balls[i].yCoord = test(balls[i], 150.0, 350.0, 500);
			//~ balls[i].yCoord = 1.0 - test(balls[i], 150.0, 350.0);	// + 1.0;
			
			
			//~ for (int i = 0; i < BALLS; i++) {
		//~ float circle = createCircle(balls[i]);		
		//~ canvas += circle * balls[i].color;
	//~ }
		}
	}
	
	for (int i = 0; i < BALLS; i++) {
		float circle = createCircle(balls[i]);		
		canvas += circle * balls[i].color;
	}
		
	color = vec4(canvas, 1.0);
	
	//~ color = vec4(abs(sin(time)), 0.0, 0.0, 1.0);
	//~ color = vec4(1.0, 0.0, 0.0, 1.0);
	//~ color = vec4(time / 10.0, 0.0, 0.0, 1.0);
}
