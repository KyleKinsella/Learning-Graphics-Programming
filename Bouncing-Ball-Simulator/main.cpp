#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "Circle/Circle.h"
#include "Utils/GUI/gui.h"

#define SCREEN_WIDTH 2066
#define SCREEN_HEIGHT 1200
#define NAME "Bouncing Ball Simulator"

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
	
	//~ float positions[] {
		//~ -1.0f, -1.0f,
		 //~ 1.0f, -1.0f,
		//~ -1.0f,  1.0f,
		 //~ 1.0f,  1.0f
	//~ };
	
	float positions[] {
		-250.0f, -250.0f, 0.0f, 0.0f, // 0
		150.0f, -250.0f, 1.0f, 0.0f, // 1
		150.0f, 150.0f, 1.0f, 1.0f, // 2
		-250.0f, 150.0f, 0.0f, 1.0f // 3
	};
	
	unsigned int indexes[] {
		0, 1, 2,
		2, 3, 0 
	};
	
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), positions, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	
	unsigned int index;
	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indexes, GL_STATIC_DRAW);
	
	glm::vec3 circleColor = glm::vec3(1.0, 0.0, 0.0);
	Circle circle(12.0f, 25.0f, 120.0f, 400.0f, circleColor);
	
	Shader shader("resources/shaders/VertexShader.glsl", "resources/shaders/FragmentShader.glsl");
	shader.bind();
	
	Gui gui(window);
	gui.setImGuiStyle(16.0f);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
		float time = glfwGetTime();
		std::cout << time << std::endl;
		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
		gui.initImGuiEveryFrame();
		gui.init(shader, "Make a ball\n\n", "\n\nUpdate a Balls Attributes");
		gui.drawImGuiToScreen();
		
        // Make our ball move each time we press the 'e' key
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			std::cout << "E KEY WAS PRESSED" << std::endl;
			glUniform1f(shader.getUniformName("time"), time);
			
			float newYVal = circle.updateBallsYCoordinate(circle, 4.0f*2.0f, time);
			glUniform1f(shader.getUniformName("u_newYVal"), newYVal);

			float result = circle.dropBall(newYVal, 130.0f);			
			glUniform1f(shader.getUniformName("u_result"), result);
		}
				
        //~ glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        //~ glDrawArrays(GL_TRIANGLES, 0, 4); 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
