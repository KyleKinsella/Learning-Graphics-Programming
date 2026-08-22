#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include "vendors/imgui/imgui.h"
#include "vendors/imgui/imgui_impl_opengl3.h"
#include "vendors/imgui/imgui_impl_glfw.h"

#include <iostream>

#include "Circle/Circle.h"
#include "Shader/Shader.h"

#define SCREEN_WIDTH 1060
#define SCREEN_HEIGHT 600
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
	
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	ImGui::StyleColorsDark();
	
	glm::vec3 a = glm::vec3(200, 200, 0);
	glm::vec3 b = glm::vec3(400, 200, 0);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
		float time = glfwGetTime();
		std::cout << time << std::endl;
		
		/* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		//~ if (ImGui::Button("Test")) {
			//~ std::cout << "the Test button was clicked!" << std::endl;
		//~ }
		
		ImGui::Text("Make a Ball\n\n");
		static float one[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("lowerEdge, higherEdge", one);
		
		static float two[2] = { 0.0f, 0.0f };
		ImGui::InputFloat2("xCoord, yCoord", two);
		
		//~ static float color[4] = { 0.10f, 0.20f, 0.30f, 0.44f };
		//~ ImGui::InputFloat4("color", color);

		static float color[3] = { 0.10f, 0.20f, 0.30f };		
		ImGui::InputFloat3("color", color);
		
		//~ ImGui::InputFloat3("color", circleColor);
		
		ImGui::Text("Textures (TODO)");
		
		//~ if (ImGui::Button("Make a Ball")) {
		//~ }
		//~ if (ImGui::Button("Change ball color")) {
		//~ }
		//~ if (ImGui::Button("Change ball fade")) {
		//~ }
		//~ if (ImGui::Button("Change ball thickness")) {
		//~ }
		
		if (ImGui::Button("Send Uniforms to GPU!")) {
			glUniform1f(shader.getUniformName("lowerEdge"), one[0]);
			glUniform1f(shader.getUniformName("higherEdge"), one[1]);
			
			glUniform1f(shader.getUniformName("xCoord"), two[0]);
			glUniform1f(shader.getUniformName("yCoord"), two[1]);
			
			//~ glUniform4f(shader.getUniformName("color"), color[0], color[1], color[2], color[3]);
			
			glUniform3f(shader.getUniformName("color"), color[0], color[1], color[2]);
			
			//~ glUniform1f(shader.getUniformName("r"), color[0]);
			//~ glUniform1f(shader.getUniformName("g"), color[1]);
			//~ glUniform1f(shader.getUniformName("b"), color[2]);
			
			//~ glUniform1f(shader.getUniformName("a"), color[3]);
		}
		
		ImGui::Text("\n\n");
		ImGui::Text("Update a particular ball and some data about that ball");
		ImGui::Text("\n\n");
		
		//~ static int count = 0;
		//~ float space = ImGui::GetStyle().ItemInnerSpacing.x;
		
		//~ if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { count--; }
		
		//~ ImGui::SameLine(0.0f, space);	
		
		//~ if (ImGui::ArrowButton("##right", ImGuiDir_Right)) {
			//~ count++;
		//~ }
			
		//~ ImGui::SameLine();	
			
		//~ ImGui::Text("%d", count);
		
		//~ if (ImGui::Button("Reset counter")) {
			//~ std::cout << "the Test button was clicked!" << std::endl;
			
			//~ count = 0;
		//~ }
		
		//~ if (ImGui::BeginMainMenuBar()) {
			//~ if (ImGui::BeginMenu("File")) {
				//~ if (ImGui::MenuItem("New")) { }
				//~ if (ImGui::MenuItem("Open", "Ctrl+O")) { }
				//~ if (ImGui::MenuItem("Save", "Ctrl+S")) { }
				//~ ImGui::Separator();
				//~ if (ImGui::MenuItem("Quit", "Alt+F4")) { }
				//~ ImGui::EndMenu();
			//~ }
			
			//~ if (ImGui::BeginMenu("Edit")) {
				//~ if (ImGui::MenuItem("Undo", "Ctrl+Z")) { }
				//~ if (ImGui::MenuItem("Redo", "Ctrl+Y", false, false)) { }  // Disabled
				//~ ImGui::EndMenu();
			//~ }
			//~ ImGui::EndMainMenuBar();
		//~ }
		
		ImGui::Text("MVP Matrix");
		ImGui::SliderFloat3("Translation A", &a.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B", &b.x, 0.0f, 960.0f);
		
		ImGui::Text("Physics (TODO)");
		
        shader.bind();
        
        // Make our ball move each time we press the 'e' key
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {	
			std::cout << "E KEY WAS PRESSED" << std::endl;			
			glUniform1f(shader.getUniformName("time"), time);		
		} 
		       
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                
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
    
    glfwTerminate();
    return 0;
}
