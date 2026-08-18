#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
//~ #include <vector>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

#define SCREEN_WIDTH 1066 //3840
#define SCREEN_HEIGHT 600 //2400
#define NAME "Bouncing Ball Simulator"


//~ #include <cstdlib>
//~ #include <ctime>


//~ void drawCircle(float centerX, float centerY, float radius, int res) {
	//~ glBegin(GL_TRIANGLE_FAN);
	//~ glVertex2d(centerX, centerY);
	//~ for (int i = 0; i < res; ++i) {
		//~ float angle = 2.0f * 3.141592653589 * (static_cast<float>(i) / res);
		//~ float x = centerX + cos(angle) * radius;
		//~ float y = centerY + sin(angle) * radius;
		//~ glVertex2d(x, y);
	//~ }
	//~ glEnd();
//~ }

//~ struct Ball {
    //~ float x, y; // Position
    //~ float velocityX, velocityY; // Velocity
//~ };

//~ Ball ball = {0.0f, 0.0f, 0.01f, 0.01f}; // Initial position and velocity


//~ void updateBallPosition() {
    //~ ball.x += ball.velocityX;
    //~ ball.y += ball.velocityY;

    //~ // Check for boundary collisions
    //~ if (ball.x > 1.0f || ball.x < -1.0f) {
        //~ ball.velocityX = -ball.velocityX; // Reverse direction
    //~ }
    //~ if (ball.y > 1.0f || ball.y < -1.0f) {
        //~ ball.velocityY = -ball.velocityY; // Reverse direction
    //~ }
//~ }


int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, NAME, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return -1;
	}
	
	float positions[] {
		-1.0f, -1.0f,
		 1.0f, -1.0f,
		-1.0f,  1.0f,
		 1.0f,  1.0f
	};
	
	float indexes[] {
		0, 1, 2,
		2, 3, 0 
	};
		
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 8 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	
	unsigned int index;
	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * 2 * sizeof(float), indexes, GL_STATIC_DRAW);
	
	glm::vec3 circleColor = glm::vec3(1.0, 0.0, 0.0);
	Circle circle(0, 1, 0, circleColor);
	
	Shader shader("resources/shaders/VertexShader.glsl", "resources/shaders/FragmentShader.glsl");
	shader.bind();
	
	
	//~ float time = glfwGetTime();
	//~ std::cout << time << std::endl;
	
	
	//~ int loc = shader.getUniformName("time");
	
	//~ std::srand(std::time(0)); // Seed with current time
	
	
	//~ if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		//~ std::cout << "the escape button was pressed!" << std::endl;
	//~ }
	
	//~ std::vector<float> pos = {400.0f, 300.0f};
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

		float time = glfwGetTime();
		std::cout << time << std::endl;

	//~ if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		//~ std::cout << "the escape button was pressed!" << std::endl;
	//~ }

        //~ updateBallPosition();

		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        //~ drawCircle(pos[0], pos[1], 50.0f, 50);
        //~ pos[1] -= 1.0f;
        
        //~ glPushMatrix();
		
		//~ glTranslatef(ball.x, ball.y, 0.0f); // Move the ball
		
		// Draw the ball (e.g., using glutSolidSphere)
		//~ glPopMatrix();
        
        //~ updateBallPosition();
        
        //~ glPushMatrix();
		//~ glTranslatef(ball.x, ball.y, 0.0f); // Move the ball
		// Draw the ball (e.g., using glutSolidSphere)
		//~ glPopMatrix();
		
		
        //~ float randomFloat = static_cast<float>(std::rand()) / RAND_MAX; // Random float between 0.0 and 1.0
        //~ shader.createNBalls("time", randomFloat);
        
        shader.bind();
        shader.createNBalls("time", time);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
