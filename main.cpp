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
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
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
		100.0f, 100.0f, 0.0f, 0.0f, // 0
		200.0f, 100.0f, 1.0f, 0.0f, // 1
		200.0f, 200.0f, 1.0f, 1.0f, // 2
		100.0f, 200.0f, 0.0f, 1.0f // 3
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
	
	// all this does is it converts our positions array to be in the range of -1 - 1.
	glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));
	
	// the multiplication goes from right to left
	glm::mat4 mvp = proj * view * model;
	
	const std::string vs = "../res/shaders/vertexShader.shader";
	const std::string fs = "../res/shaders/fragmentShader.shader";
	
	Shader shader(vs, fs);
	shader.bind();
	shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	shader.setUniformMat4f("u_MVP", mvp);
	
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
