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

#define SCREEN_WIDTH 1066 //960
#define SCREEN_HEIGHT 600 //540
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
		//~ -1.0f, -1.0f, 1.0f, 1.0f,
		 //~ 1.0f, -1.0f, 1.0f, 0.0f,
		//~ -1.0f,  1.0f, 0.0f, 0.0f,
		 //~ 1.0f,  1.0f, 0.0f, 1.0f
	//~ };
	
	//~ float positions[] = {
			//~ -0.5f, -0.5f, 0.0f, 0.0f, // 0
			//~ 0.5f, -0.5f, 1.0f, 0.0f, // 1
			//~ 0.5f, 0.5f, 1.0f, 1.0f, // 2
			//~ -0.5f, 0.5f, 0.0f, 1.0f // 3
		//~ };
		
	
	//~ float positions[] {
			//~ -150.0f, -150.0f, 0.0f, 0.0f, // 0
			//~ 50.0f, -150.0f, 1.0f, 0.0f, // 1
			//~ 50.0f, 50.0f, 1.0f, 1.0f, // 2
			//~ -150.0f, 50.0f, 0.0f, 1.0f // 3
		//~ };
		
	
	//~ float positions[] {
		//~ -1.0f, -1.0f,
		 //~ 1.0f, -1.0f,
		//~ -1.0f,  1.0f,
		 //~ 1.0f,  1.0f
	//~ };
	
	
	//~ -150.0f, -150.0f, 0.0f, 0.0f, // 0
			//~ 50.0f, -150.0f, 1.0f, 0.0f, // 1
			//~ 50.0f, 50.0f, 1.0f, 1.0f, // 2
			//~ -150.0f, 50.0f, 0.0f, 1.0f // 3
			
			
	//~ float positions[] {
			//~ -150.0f, -150.0f, 0.0f, 0.0f, // 0
			//~ 50.0f, -150.0f, 1.0f, 0.0f, // 1
			//~ 50.0f, 50.0f, 1.0f, 1.0f, // 2
			//~ -150.0f, 50.0f, 0.0f, 1.0f // 3
		//~ };
		
			
	//~ float positions[] = {
			//~ -0.5f, -0.5f, 0.0f, 0.0f,// 0
			 //~ 0.5f, -0.5f, 1.0f, 0.0f,// 1
			 //~ 0.5f, 0.5f, 1.0f, 1.0f,// 2
			//~ -0.5f, 0.5f, 0.0f, 1.0f// 3
		//~ };		
		
	//~ float positions[] = {
			//~ -0.5f, -0.5f, 0.0f, 1.0f,// 0
			 //~ 0.5f, -0.5f, 1.0f, 1.0f,// 1
			 //~ 0.5f, 0.5f, 1.0f, 1.0f,// 2
			//~ -0.5f, 0.5f, 0.0f, 1.0f// 3
		//~ };		
			
	//~ float positions[] {
		//~ -1.0f, -1.0f, 0.0f, 0.0f,
		 //~ 1.0f, -1.0f, 1.0f, 0.0f,
		//~ -1.0f,  1.0f, 0.1f, 1.0f,
		 //~ 1.0f,  1.0f, 0.0f, 1.0f
	//~ };
	
	//~ float positions[] {
		//~ -1.0f, -1.0f, 0.0f, 1.0f,
		 //~ 1.0f, -1.0f, 1.0f, 1.0f,
		//~ -1.0f,  1.0f, 1.1f, 0.0f,
		 //~ 1.0f,  1.0f, 0.0f, 0.0f
	//~ };
	
	//~ float positions[] {
		//~ -150.0f, -150.0f, 0.0f, 1.0f,
		 //~ 50.0f, -150.0f, 1.0f, 1.0f,
		//~ -150.0f,  50.0f, 1.0f, 0.0f,
		 //~ 50.0f,  50.0f, 0.0f, 0.0f
	//~ };
	
	
	
	
	
	
	
	
	float positions[] {
			-150.0f, -150.0f, 0.0f, 0.0f, // 0
			50.0f, -150.0f, 1.0f, 0.0f, // 1
			50.0f, 50.0f, 1.0f, 1.0f, // 2
			-150.0f, 50.0f, 0.0f, 1.0f // 3
		};
	
	unsigned int indexes[] {
		0, 1, 2,
		2, 3, 0 
	};
	
	// blending
	//~ glEnable(GL_BLEND);
	//~ glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), positions, GL_STATIC_DRAW);

	//~ glBindBuffer(GL_ARRAY_BUFFER, buffer);
	
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	
	
	//~ glBindBuffer(GL_ARRAY_BUFFER, buffer);
	
	//~ unsigned int vao;
	//~ glGenVertexArrays(1, &vao);
	//~ glBindVertexArray(vao);
	
	
	
	//~ glEnableVertexAttribArray(1);
	//~ glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	
	//~ glEnableVertexAttribArray(2);
	//~ glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	
	//~ int width, height, nrChannels;	
	//~ stbi_set_flip_vertically_on_load(true);
	//~ unsigned char* data = stbi_load("resources/textures/sun.jpg", &width, &height, &nrChannels, 0);

	//~ unsigned int texture;
	//~ glGenTextures(1, &texture);
	//~ glBindTexture(GL_TEXTURE_2D, texture);
	
	//~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	//~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // Trilinear Filtering
    //~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               // Bilinear Filtering
	
	//~ int width, height, nrChannels;	
	//~ stbi_set_flip_vertically_on_load(true);
	
	//~ unsigned char* data = stbi_load("resources/textures/sun.jpg", &width, &height, &nrChannels, 0);
	
	//~ if (data) {
		//~ glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //~ std::cout << "Texture successfully loaded and mapped." << std::endl;
	//~ } else {
		//~ std::cout << "FATAL ERROR: Failed to load texture file 'container.jpg'." << std::endl;
	//~ }
	
	//~ stbi_image_free(data);
	
	//~ glActiveTexture(GL_TEXTURE0);
	//~ glBindTexture(GL_TEXTURE_2D, texture);
	
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
	const std::string& path = "resources/textures/er.jpg";
	unsigned char* img = stbi_load(path.c_str(), &width, &height, &bpp, 4);
	
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // S and T are the same as X and Y but for textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
	glBindTexture(GL_TEXTURE_2D, 0); // wait, we have to unbind here!?
	
	if (img)
		stbi_image_free(img);
		
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glm::vec3 a = glm::vec3(200, 200, 0);
	
	glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ glm::mat4 model = glm::translate(glm::mat4(1.0f), a);
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ glm::mat4 matrix = proj * view * model;
	
	//~ glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &matrix[0][0]);
		
		
		
		
		
		
		
	//~ glUniform4f()
	
	//~ glm::mat4 proj = 
	
	//---------------------------============================================================================================

	//~ int width, height, nrChannels;	
	//~ stbi_set_flip_vertically_on_load(true);
	//~ unsigned char* data = stbi_load("resources/textures/sun.jpg", &width, &height, &nrChannels, 0);
	
	//~ unsigned int textureId;
	//~ glGenTextures(1, &textureId);
	//~ glBindTexture(GL_TEXTURE_2D, textureId);
	//~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//~ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	//~ glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//~ stbi_image_free(data);
	
	//~ glActiveTexture(GL_TEXTURE0);
	//~ glBindTexture(GL_TEXTURE_2D, textureId);
	
	//~ glUniform1i(shader.getUniformName(""))
	
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
		
		ImGui::Text("Textures (TODO)");
		
		if (ImGui::Button("Create Ball")) {
			glUniform1f(shader.getUniformName("lowerEdge"), one[0]);
			glUniform1f(shader.getUniformName("higherEdge"), one[1]);
			
			glUniform1f(shader.getUniformName("xCoord"), two[0]);
			glUniform1f(shader.getUniformName("yCoord"), two[1]);
			
			glUniform3f(shader.getUniformName("color"), color[0], color[1], color[2]);
		}
		
		ImGui::Text("\n\n");
		ImGui::Text("Update a particular ball and some data about that ball");
		ImGui::Text("\n\n");
		
		ImGui::Text("MVP Matrix");
		ImGui::Text("Physics (TODO)");
		
		//~ glActiveTexture(GL_TEXTURE0);
		//~ glBindTexture(GL_TEXTURE_2D, texture);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glm::mat4 model = glm::translate(glm::mat4(1.0f), a);
       	glm::mat4 matrix = proj * view * model;
       	

        shader.bind();
        
        
        glUniformMatrix4fv(shader.getUniformName("u_MVP"), 1, GL_FALSE, &matrix[0][0]);

        
        glUniform1i(shader.getUniformName("u_Texture"), 0);
        
        ImGui::SliderFloat3("TEST", &a.x, 0.0f, 960.0f);
        
        
        
        
        //~ ImGui::SliderFloat3("Translation A", &m_TranslationA.x, 0.0f, 960.0f);
		//~ ImGui::SliderFloat3("Translation B", &m_TranslationB.x, 0.0f, 960.0f);
        
        //~ glUniform1i(shader.getUniformName("ourTexture"), 0);
        
        // Make our ball move each time we press the 'e' key
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			std::cout << "E KEY WAS PRESSED" << std::endl;		
			glUniform1f(shader.getUniformName("time"), time);
		}
				     
		//~ shader.bind();
		
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
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
    glDeleteVertexArrays(1, &vao);
    
    glfwTerminate();
    return 0;
}
