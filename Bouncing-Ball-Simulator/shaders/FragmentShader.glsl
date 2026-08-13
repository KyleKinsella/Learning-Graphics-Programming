#version 330 core

layout (location = 0) out vec4 color;

#define UV gl_FragCoord.xy

//~ uniform const int ballsToMake;


//~ uniform int ballsToMake;


//~ #include "../../Circle/Circle.h"

//~ #include <cstdlib>

//~ #define MAX_BALLS ballsToMake

//~ uniform int sizeLow;
//~ uniform int sizeHigh;

//~ uniform int x;
//~ uniform int y;

#define BALLS 5

struct Ball {
	float lowerEdge;
	float higherEdge;
	float xCoord;
	float yCoord;
	//~ int lowerEdge;
	//~ int higherEdge;
	//~ int xCoord;
	//~ int yCoord;
	vec3 color;
};

// TODO: add color...
float createCircle(float lowerEdge, float higherEdge, float xCoord, float yCoord) {
	return 1.0 - smoothstep(lowerEdge, higherEdge, distance(UV, vec2(xCoord, yCoord)));
}

//~ float createCircle(float lowerEdge, float higherEdge, float xCoord, float yCoord) {
	//~ float count = 0.0;
	//~ for (int i = 0; i < BALLS; i++)
		//~ count /= smoothstep(lowerEdge, higherEdge, distance(UV, vec2(xCoord, yCoord)));
		
	//~ return 1.0 - count;
//~ }

//~ 50
//~ float createCircleAndBall(Ball balls[BALLS]) {
	//~ for (int i = 0; i < balls.length(); i++)
		//~ return 1.0 - smoothstep(balls[i].lowerEdge, balls[i].higherEdge, distance(UV, vec2(balls[i].xCoord, balls[i].yCoord)));
//~ }

float createCircleAndBall(Ball ball) {
	return 1.0 - smoothstep(ball.lowerEdge, ball.higherEdge, distance(UV, vec2(ball.xCoord, ball.yCoord)));
}

void main() {
	float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	float purpleCircle = createCircle(2.0, 5.0, 640.0, 320.0);
	//~ float purpleCircle = createCircle(22.0, 32.0, 640.0, 320.0);
	float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
	
	redCircle = 1.0 - createCircle(25.0, 5.0, 120.0, 500.0);
	
	//~ redCircle = 1.0 - createCircle(sizeLow, sizeHigh, x, y);
	//~ whiteCircle = 1.0 - createCircle(12.0, 50.0, 245.0, 345.0);
	
	vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(0.65, 0.56, 1.0) * purpleCircle + vec3(1.0, 0.55, 0.76) * pinkCircle;
	
	
	//~ color = vec4(canvas, 1.0);
	
	
	Ball balls[BALLS];
	//~ vec3 total;
	//~ float nBalls;
	
	for (int i = 0; i < balls.length(); i++) {
		//~ Ball b;
		//~ b[i].lowerEdge = sizeLow;
		//~ b[i].higherEdge = sizeHigh;// + i;
		//~ b[i].xCoord = x + i + 5;// * 1066;
		//~ b[i].yCoord = y + i * 5;// * 600;
		//~ b[i].color = vec3(1.0, 0.0, 0.0);

		//~ balls[i] = b;


		//~ balls[i] = balls[b];
		
		//~ balls[i] = b;

		
		//~ nBalls = createCircleAndBall(balls[i]);
		//~ nBalls = createCircleAndBall(balls);
		//~ canvas += nBalls;// + BALLS + 1066 + 600;	// * BALLS;
		
		
		
		//~ color = vec4(canvas, 1.0);
		
		//~ balls[i] = b;

		//~ b = balls[i];
		//~ color = vec4(canvas * balls[i].color, 1.0);

		//~ color = vec4(canvas * balls[i].color, 1.0);
	//~ }
	
	
	//~ color = vec4(canvas, 1.0);
	
	//~ for (int j = 0; j < balls.length(); j++) {
		//~ color = vec4(canvas*balls.color, 1.0);
		
		
		balls[i].lowerEdge = 12.0;
		balls[i].higherEdge = 25.0;
		balls[i].xCoord = 100.0 + float(i) * 130.0;
		balls[i].yCoord = 200.0;
		
		balls[i].color = vec3(1.0, 0.0, 0.0);
		//~ balls[i].color = vec3(1.0, 1.0, 1.0);
	}
	
	
	for (int i = 0; i < BALLS; i++) {
		float circle = createCircleAndBall(balls[i]);
		canvas += circle * balls[i].color;
	}
	

	color = vec4(canvas, 1.0);
	 //~ color = vec4(
		//~ UV.x / 1066.0,
		//~ UV.y / 600.0,
		//~ 0.0,
		//~ 1.0
	//~ );
	
	
	//~ --------------------------------------------------------------------------------------------------
	
	//~ Ball ball;
	//~ ball.lowerEdge = 12.0f; 
	//~ ball.higherEdge = 50.0f; 
	//~ ball.xCoord = 245.0f;
	//~ ball.yCoord = 345.0f;
	
	//~ ball *= redCircle;
	
	//~ vec3 canvas = vec3(0.0);
	//~ canvas += whiteCircle * redCircle * purpleCircle * pinkCircle * vec3(1.0, 0.0, 0.0);
	
	//~ vec3 canvas = whiteCircle * redCircle * purpleCircle * pinkCircle * vec3(1.0, 0.0, 0.0);
	
	//~ color = vec4(canvas * ballsToMake, 1.0);
	
	
	//~ float myArray[MAX_BALLS];
	
	//~ float myArray[ballsToMake];
	
	
	// works!!!! :
	//~ float myArray[50];
	//~ for (int i = 0; i < myArray.length(); i++) {
		//~ myArray[i] = float(vec3(1.0, 0.0, 0.0));
		//~ color = vec4(canvas * myArray[i], 1.0);
	//~ }
	
	
	//~ 50
	//~ Ball balls[BALLS];
	//~ vec3 total;	// = vec3(0.0);
	//~ float nBalls;
	//~ for (int i = 0; i < BALLS; i++) {
		
		//~ if (i == 0) 
			//~ continue;
				
		//~ if (balls[i].lowerEdge > 25.0)
			//~ continue;
			
		//~ if (balls[i].higherEdge > 80.0)
			//~ continue;
			
		//~ if (balls[i].xCoord >  640.0)
			//~ continue;
			
		//~ if (balls[i].yCoord >  500.0)
			//~ continue;
		
		//~ balls[i].lowerEdge = i * 500;// - 1;// + 25;
		//~ balls[i].higherEdge = i - 5;//00;// * 2; //1;// - 5; //-
		//~ balls[i].higherEdge = i * 500; //1;// - 5; //-
		//~ balls[i].xCoord = i + 10;//* 20;
		//~ balls[i].yCoord = i - 10;//* 40;// - 10;
		//~ balls[i].color = vec3(1.0, 0.0, 0.0);
		
		
		
		// works:
		//~ balls[i].lowerEdge = sizeLow;
		//~ balls[i].higherEdge = sizeHigh;// + i;
		
		
		
		//~ balls[i].higherEdge = i * 500; //1;// - 5; //-
		
		//works:
		//~ balls[i].xCoord = x + i + 5 * 1066;
		
		
		//~ balls[i].xCoord = x + 1066;
		
		// works:
		//~ balls[i].yCoord = y * 600;
		//~ balls[i].color = vec3(1.0, 0.0, 0.0);
		
		//~ total += 1.0 - balls[i].lowerEdge * balls[i].higherEdge * balls[i].xCoord * balls[i].yCoord * balls[i].color;
		
		//~ color = vec4(canvas + total, 1.0);
		
		
		//~ vec3 nBalls = createCircleAndBall(balls);
		
		//~ nBalls = 1.0 - createCircleAndBall(balls);
		
		//~ nBalls = 1.0 - createCircleAndBall(balls[i]);
		
		
		
		// works:
		//~ nBalls = createCircleAndBall(balls[i]);
		
		
		
		
		//~ nBalls = createCircleAndBall(balls[i]);
		//~ nBalls = createCircleAndBall(balls);
		//~ canvas += nBalls * BALLS;
		
		
		
		
		
		// works:
		//~ canvas += nBalls;// + BALLS + 1066 + 600;	// * BALLS;
		
		
		
		
		
		
		
		
		
		//~ canvas += balls[i];
		
		//~ color = vec4(canvas * nBalls, 1.0);
		
		
		//~ color = vec4(canvas * total, 1.0);
		
		
		//~ color = vec4(canvas, 1.0);
		
		//~ color = vec4(canvas * balls[i].color, 1.0);
		
		
			//~ color = vec4(canvas * balls[i].color, 1.0);
			
				//~ color = vec4(canvas, 1.0);

	//~ color = vec4(total, 1.0);

		//~ for (int j = 0; j < balls.length(); j++) {
			//~ color = vec4(canvas*balls[j].color, 1.0);
		//~ }

	//~ }
	
	
	
	
	
	
	
	//~ color = vec4(canvas, 1.0);
	
	//~ for (int j = 0; j < balls.length(); j++) {
		//~ color = vec4(canvas*balls.color, 1.0);
	//~ }







	//~ color = vec4(total, 1.0);
	//~ color = vec4(canvas, 1.0);
	//~ color = vec4(canvas * balls.color, 1.0);
	
	
	
	//~ float lowerEdgeValues[] = {12.0};
	//~ float higherEdgeValues[] = {};
	
	//~ float count = 0.0;
	//~ for (int i = 0; i < ballsToMake; i++) {
		//~ canvas *= i;
		
		//~ Ball ball;
		//~ ball.
	//~ }
	
	//~ color = vec4(canvas * myArray, 1.0);
	
	//~ color = vec4(vec3(ball), 1.0);
}
