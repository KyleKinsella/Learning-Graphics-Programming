#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Bouncing Ball Simulator", NULL, NULL);
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
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f,
		-0.5f, 0.5f	
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
	
	//~ glEnableVertexAttribArray(1);
	//~ glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	
	Circle circle(0, 1, 0, glm::vec3(0.2, 0.3, 0.8));
	
	Shader shader("resources/shaders/VertexShader.glsl", "resources/shaders/fragmentTestShader.glsl");
	shader.bind();
	
    //~ /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
		shader.bind();
        shader.sendUniformValue("iResolution", 640.0f, 480.0f, 1.0f);
        shader.sendUniformValue("color", 1.0f, 0.0f, 0.67f);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
