#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

#define SCREEN_WIDTH 1066
#define SCREEN_HEIGHT 600
#define NAME "Bouncing Ball Simulator"

#include <cstdlib>
#include <ctime>

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
	
	//~ float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	//~ float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	//~ float purpleCircle = createCircle(2.0, 5.0, 640.0, 320.0);
	
	
	//~ float purpleCircle = createCircle(22.0, 32.0, 640.0, 320.0);
	
	
	//~ float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
	
	//~ float lowerEdgeValues[] = {2.0, 12.0, 20.0, 25.0};
	//~ float higherEdgeValues[] = {5.0, 23.0, 50.0, 80.0};
	
    //~ int sizeLow = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
    //~ int sizeHigh = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
    
	//~ float xValues[] = {120.0, 210.0, 245.0, 640.0};
	//~ float yValues[] = {80.0, 320.0, 345.0, 500.0};
	
    //~ int x = sizeof(xValues) / sizeof(xValues[0]);
    //~ int y = sizeof(yValues) / sizeof(yValues[0]);
    
    //~ std::srand(std::time(nullptr)); // Seed the random number generator
    //~ int randomLowIndex = std::rand() % sizeLow; // Get a random index
    //~ int randomHighIndex = std::rand() % sizeHigh; // Get a random index
    
    //~ int xIndex = std::rand() % x; // Get a random index
    //~ int yIndex = std::rand() % y; // Get a random index
    
    
    //~ std::cout << "Random float: " << lowerEdgeValues[randomLowIndex] << ", " << higherEdgeValues[randomHighIndex] << std::endl;
		
		
	//~ float lowerEdgeValues[] = {2.0, 12.0, 20.0, 25.0};
	//~ float higherEdgeValues[] = {5.0, 23.0, 50.0, 80.0};
	
	//~ int sizeLow = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
	//~ int sizeHigh = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
	
	//~ float xValues[] = {120.0, 210.0, 245.0, 640.0};
	//~ float yValues[] = {80.0, 320.0, 345.0, 500.0};
	
	//~ int x = sizeof(xValues) / sizeof(xValues[0]);
	//~ int y = sizeof(yValues) / sizeof(yValues[0]);
	
		
    //~ /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        //~ shader.bind();
        //~ shader.createNBalls("ballsToMake", 50);
        
     		
	float lowerEdgeValues[] = {3.0, 6.0, 9.0, 12.0};
	float higherEdgeValues[] = {24.0, 33.0, 55.0, 88.0};
	
	int sizeLow = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
	int sizeHigh = sizeof(lowerEdgeValues) / sizeof(lowerEdgeValues[0]);
	
	float xValues[] = {125.0, 250.0, 275.0, 295.0};
	float yValues[] = {300.0, 320.0, 345.0, 500.0};
	
	int x = sizeof(xValues) / sizeof(xValues[0]);
	int y = sizeof(yValues) / sizeof(yValues[0]);
		
		std::srand(std::time(nullptr)); // Seed the random number generator
		//~ int randomLowIndex = std::rand() % sizeLow; // Get a random index
		//~ int randomHighIndex = std::rand() % sizeHigh; // Get a random index
		
		float randomLowIndex = lowerEdgeValues[std::rand() % sizeLow];
		float randomHighIndex = higherEdgeValues[std::rand() % sizeHigh];
		
		
		float xIndex = xValues[std::rand() % x];
		float yIndex = yValues[std::rand() % y];

		
		
		//~ int xIndex = std::rand() % x; // Get a random index
		//~ int yIndex = std::rand() % y; // Get a random index
    
		//~ glUniform1i(shader.getUniformName("sizeLow"), sizeLow);
		//~ glUniform1i(shader.getUniformName("sizeHigh"), sizeHigh);
		
		
		// works:
		//~ glUniform1f(shader.getUniformName("sizeLow"), sizeLow);
		//~ glUniform1f(shader.getUniformName("sizeHigh"), sizeHigh);
		
		
		
		
		//~ std::cout << "Random float: " << lowerEdgeValues[randomLowIndex] << ", " << higherEdgeValues[randomHighIndex] << xValues[x] <<  ", " << yValues[y] << std::endl;

		
		//~ glUniform1i(shader.getUniformName("x"), x);
		//~ glUniform1i(shader.getUniformName("y"), y);
        
        
        //~ // works:
		//~ glUniform1f(shader.getUniformName("x"), x);
		//~ glUniform1f(shader.getUniformName("y"), y);
        
        
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
