#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

//~ #define SCREEN_WIDTH 230
//~ #define SCREEN_HEIGHT 220

//~ #define SCREEN_WIDTH 2066
//~ #define SCREEN_HEIGHT 1000

#define SCREEN_WIDTH 1066
#define SCREEN_HEIGHT 600

//~ #define SCREEN_WIDTH 670
//~ #define SCREEN_HEIGHT 650

//~ #define SCREEN_WIDTH 1066
//~ #define SCREEN_HEIGHT 600

//~ #define N 2

//~ #define SCREEN_WIDTH 350
//~ #define SCREEN_HEIGHT 500

#define NAME "Bouncing Ball Simulator"

//~ glm::vec3 createCircle(glm::vec2 position, glm::vec3 color, float size) {
	//~ float circle = sqrt(pow(position.x, 2.0) + pow(position.y, 2.0));
	//~ circle = glm::smoothstep(size, size + 0.003, 1.0 - circle);
	
	//~ return color * circle;
//~ }

//~ glm::vec3 createCircle(glm::vec2 position, glm::vec3 color, float size) {
	//~ float circle = sqrt(pow(position.x, 2.0) + pow(position.y, 2.0));
	//~ circle = smoothstep(size, size + 0.003, 1.0 - circle);
	
	//~ return color * circle;
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
    
    //~ int w = 0, h = 0;
	//~ glfwGetFramebufferSize(window, &w, &h); // if using GLFW
	//~ glViewport(0, 0, w, h);

	//~ glUseProgram(program);
	//~ glUniform2f(uResolutionLocation, (float)w, (float)h);
	
	//~ glUniform2f(shader.getUniformName("u_resolution"), (float)w, (float)h);


	
	
	//~ glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	
	
    
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return -1;
	}
    
    //~ float positions[] {
		//~ -0.5f, -0.5f,
		//~ 0.0f, 0.5f,	
		//~ 0.5f, -0.5f,
		//~ -0.5f, 0.5f	
	//~ };
	
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
	
	//~ glEnableVertexAttribArray(0);
	//~ glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	
	unsigned int index;
	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * 2 * sizeof(float), indexes, GL_STATIC_DRAW);
	
	//~ glEnableVertexAttribArray(1);
	//~ glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	
	//~ glm::vec3 circleColor = glm::vec3(0.2, 0.3, 0.8);
	
	glm::vec3 circleColor = glm::vec3(1.0, 0.0, 0.0);
	Circle circle(0, 1, 0, circleColor);
	
	// for testing purposes only!
	//~ std::string fragmentShaders[] = {
		//~ "resources/shaders/FragmentShader.glsl",
		//~ "resources/shaders/fragmentTestShader.glsl",
		//~ "resources/shaders/testGLSL.glsl",
		//~ "resources/shaders/test.glsl"
	//~ };
	
	//~ const int n = 3;
	
	//~ Shader shader("resources/shaders/VertexShader.glsl", fragmentShaders[N]);
	
	Shader shader("resources/shaders/VertexShader.glsl", "resources/shaders/testGLSL.glsl");
	shader.bind();
	
	int dims[4] = {0};
	glGetIntegerv(GL_VIEWPORT, dims);
	int fdWidth = dims[2];
	int fdHeight = dims[3];
	
	//~ std::cout << "fd width: " << fdWidth << "fd height: " << fdHeight << std::endl; 
	//~ std::cout << fdWidth << ", " << fdHeight << std::endl; 
	
	
	//~ GLint dims[4] = {0};
	//~ glGetIntegerv(GL_SCISSOR_BOX, dims);
	//~ GLint fbWidth = dims[2];
	//~ GLint fbHeight = dims[3];

	//~ std::cout << fbWidth << ", " << fbHeight << std::endl; 
	
	
	 
    //~ int w = 0, h = 0;
	//~ glfwGetFramebufferSize(window, &w, &h); // if using GLFW
	//~ glViewport(0, 0, w, h);

	//~ glUseProgram(program);
	//~ glUniform2f(uResolutionLocation, (float)w, (float)h);
	
	//~ glUniform2f(shader.getUniformName("u_resolution"), (float)w, (float)h);
	
	
	//~ glm::vec3 data(SCREEN_WIDTH, SCREEN_HEIGHT, 1);
	
	glm::vec3 data(fdWidth, fdHeight, 1);
	
	//~ glm::vec3 data((float)w, (float)h, 1);
		
    //~ /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
		shader.bind();
		
		//~ glEnable(GL_BLEND);
		//~ glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
		// for testing purposes only!
		//~ if (N == 1 || N == 3) {
			//~ shader.sendUniformValue("iResolution", data);
			//~ shader.sendUniformValue("color", circleColor);	
		//~ }
		
		// for testing purposes only!
		//~ if (N == 2) {
		
		
			//~ glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			//~ int w = 0, h = 0;
			//~ glfwGetFramebufferSize(window, &w, &h); // if using GLFW
			//~ glViewport(0, 0, w, h);

			//~ glm::vec3 data((float)w, (float)h, 1);

			//~ glUniform2f(shader.getUniformName("u_resolution"), (float)w, (float)h);


			
			
			//~ glUniform2f(shader.getUniformName("u_resolution"), data.x, data.y);
			
			
			
			
			//~ shader.sendUniformValue("color", circleColor);
		
		
		
		
		//~ }
			        
		//~ glUniform2f(shader.getUniformName("u_resolution"), data.x-25, data.y-15);
		
		//~ glUniform2f(shader.getUniformName("u_resolution"), data.x, data.y);
		//~ shader.sendUniformValue("color", circleColor);
		        
        //~ glDrawArrays(GL_TRIANGLES, 0, 4);
        //~ glDrawArrays(GL_TRIANGLES, 0, 6);
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
