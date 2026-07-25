#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "Renderer/renderer.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"
#include "VertexBufferLayout/VertexBufferLayout.h"
#include "Textures/Texture.h"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glfwSwapInterval(1);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return -1;
	}
	
	// this is our vertex buffer
	float positions[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, // 0
		 0.5f, -0.5f, 1.0f, 0.0f, // 1
		 0.5f, 0.5f, 1.0f, 1.0f, // 2
		-0.5f, 0.5f, 0.0f, 1.0f // 3
	};
	
	// this is our index buffer
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};
	
	// blending
	glCall(glEnable(GL_BLEND));
	glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	
	// vertex array object
	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.addBuffer(vb, layout);
	
	IndexBuffer ib(indices, 6);
	
	glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	
	const std::string vs = "../res/shaders/vertexShader.shader";
	const std::string fs = "../res/shaders/fragmentShader.shader";
	
	Shader shader(vs, fs);
	shader.bind();
	shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	shader.setUniformMat4f("u_MVP", proj);
	
	Texture texture("../res/textures/sekiro.png");
	texture.bind();
	shader.setUniform1i("u_Texture", 0);
	
	// here we are un-binding everything
	va.unBind();
	vb.unBind();
	ib.unBind();
	shader.unBind();
	
	Renderer renderer;
	
	float r = 0.0f;
	float increment = 0.05f;
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
        /* Render here */
        renderer.clear();
        	
        // bind our shader
        shader.bind();
        
        // set up our uniforms
        shader.setUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
        	
        renderer.draw(va, ib, shader);
        		    
        if (r > 1.0f)
			increment = -0.05f;
		else if (r < 0.0f) 
			increment = 0.05f;
					
		r += increment;
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
