#version 330 core

layout (location = 0) out vec4 fragColor;

#define UV gl_FragCoord.xy
#define BALLS 5

uniform float time;
uniform float lowerEdge;
uniform float higherEdge;
uniform float xCoord;
uniform float yCoord;
uniform vec3 color;

uniform sampler2D u_Texture;
in vec2 u_TexCoord;

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

float updateBallsYCoordinate(Ball ball, float newYValue, float timeElapsed) {
	// a ball is zero, so give him a value so he can move
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

void main() {
	float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	float purpleCircle = createCircle(22.0, 25.0, 420.0, 350.0);
	float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
	
	float guiCircle = createCircle(lowerEdge, higherEdge, xCoord, yCoord);
	vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(0.65, 0.56, 1.0) * purpleCircle + vec3(1.0, 0.55, 0.76) * pinkCircle + color * guiCircle;
	
	Ball balls[BALLS];
	for (int i = 0; i < BALLS; i++) {
		balls[i].lowerEdge = 12.0;
		balls[i].higherEdge = 25.0;
		balls[i].xCoord = 100.0 + float(i) * 130.0;
		balls[i].yCoord = 200.0;
		balls[i].color = vec3(1.0, 0.0, 0.0);
			
		if (i == BALLS-1) {
			balls[i].color = vec3(0.0, 1.0, 0.0);
			balls[i].yCoord += updateBallsYCoordinate(balls[i], i*2.0, time);
			balls[i].yCoord -= dropBall(balls[i].yCoord, 130.0);
		}
	}
	
	for (int i = 0; i < BALLS; i++) {
		float circle = createCircle(balls[i]);		
		canvas += circle * balls[i].color;
	}
	
	//~ fragColor = vec4(canvas, 1.0);
	
	vec4 textCoord = texture(u_Texture, u_TexCoord);
	fragColor = textCoord;
	//~ fragColor = guiCircle * textCoord;
	
	//~ fragColor = vec4(UV.x / 1066.0, UV.y / 600, 0.0, 1.0);
}
