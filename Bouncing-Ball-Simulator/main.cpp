#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include "vendors/imgui/imgui.h"
#include "vendors/imgui/imgui_impl_opengl3.h"
#include "vendors/imgui/imgui_impl_glfw.h"

#include "vendors/stb/stb_image.h"

#include "vendors/glm/gtc/matrix_transform.hpp"

#include <iostream>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

#define SCREEN_WIDTH 2066
#define SCREEN_HEIGHT 1200
#define NAME "Bouncing Ball Simulator"
#define TEXTURE_NAME "resources/textures/er.jpg";

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
	
	//~ unsigned int vao;
	//~ glGenVertexArrays(1, &vao);
	//~ glBindVertexArray(vao);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	
	unsigned int index;
	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indexes, GL_STATIC_DRAW);
	
	glm::vec3 circleColor = glm::vec3(1.0, 0.0, 0.0);
	Circle circle(0, 1, 0, circleColor);
		
	Shader shader("resources/shaders/VertexShader.glsl", "resources/shaders/FragmentShader.glsl");
	shader.bind();
	
	int width, height, bpp;
	stbi_set_flip_vertically_on_load(1);
	const std::string& path = TEXTURE_NAME;
	unsigned char* img = stbi_load(path.c_str(), &width, &height, &bpp, 4);
	
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // S and T are the same as X and Y but for textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	if (img)
		stbi_image_free(img);
		
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glm::vec3 a = glm::vec3(200, 200, 0);
	glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	ImGui::StyleColorsDark();
	
	ImGuiStyle& style = ImGui::GetStyle();
	style.FontSizeBase = 18.0f;
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
		float time = glfwGetTime();
		std::cout << time << std::endl;
		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		ImGui::Text("Make a Ball\n\n");
		static float one[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("lowerEdge, higherEdge", one);
		
		static float two[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("xCoord, yCoord", two);
		
		static float color[3] = { 0.10f, 0.20f, 0.30f };	
		ImGui::InputFloat3("color", color);
		
		//~ ImGui::Text("Textures (TODO)");

		//~ ImGui::Text("\n\n");
		ImGui::Text("\n");
		
		if (ImGui::Button("Create Ball")) {
			glUniform1f(shader.getUniformName("lowerEdge"), one[0]);
			glUniform1f(shader.getUniformName("higherEdge"), one[1]);
			
			glUniform1f(shader.getUniformName("xCoord"), two[0]);
			glUniform1f(shader.getUniformName("yCoord"), two[1]);
			
			glUniform3f(shader.getUniformName("color"), color[0], color[1], color[2]);
		}
		
		//~ ImGui::Text("\n\n");
        //~ shader.bind();
        
		//~ if (ImGui::Button("Create Texture")) {
			//~ glm::mat4 model = glm::translate(glm::mat4(1.0f), a);
			//~ glm::mat4 matrix = proj * view * model;
       	
			//~ glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &matrix[0][0]);        
			//~ glUniform1i(shader.getUniformName("u_Texture"), 0);        
		//~ }
		//~ ImGui::SliderFloat2("Texture 1", &a.x, 0.0f, 960.0f);

		//~ ImGui::Text("\n\n");
		ImGui::Text("\n");
		
		//~ ImGui::Text("\n\n");
		//~ ImGui::Text("Update a particular ball and some data about that ball");
		//~ ImGui::Text("\n\n");
		
		//~ ImGui::Text("MVP Matrix");
		//~ ImGui::Text("Physics (TODO)");
		
		//~ glActiveTexture(GL_TEXTURE0);
		//~ glBindTexture(GL_TEXTURE_2D, texture);
		
		glm::mat4 model = glm::translate(glm::mat4(1.0f), a);
       	glm::mat4 matrix = proj * view * model;
       	
        shader.bind();
        
        glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &matrix[0][0]);        
        glUniform1i(shader.getUniformName("u_Texture"), 0);
        
        ImGui::SliderFloat2("Texture 1", &a.x, 0.0f, 960.0f);
        
        // Make our ball move each time we press the 'e' key
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			std::cout << "E KEY WAS PRESSED" << std::endl;		
			glUniform1f(shader.getUniformName("time"), time);
		}
		
        //~ glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        //~ glDrawArrays(GL_TRIANGLES, 0, 4);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        
		ImGui::Render();		
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
                
		/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glDeleteTextures(1, &texture);
    //~ glDeleteVertexArrays(1, &vao);
    
    glfwTerminate();
    return 0;
}
