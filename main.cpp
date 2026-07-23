#include "glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>

#define ASSERT(x) if (!(x)) raise(x);
#define glCall(x) glClearError();\
	x;\
	ASSERT(glLogCall(#x, __FILE__, __LINE__))

// clear all of our errors 
static void glClearError() {
	while (glGetError() != GL_NO_ERROR);
}

// then we check to see if we have found any errors, the errors are coming from the below function:
static bool glLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << ":" << line << std::endl;
		return false;
	}
	
	return true;
}

static std::string readShaderFile(const std::string& filePath) {
	std::ifstream file(filePath);
	
	std::string str;
	std::string content;
	while (std::getline(file, str)) {
		content.append(str + "\n");
	}
	
	return content;
}

static unsigned int compileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	
	// do we have a compiling error for either of our shaders ?
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		
		glGetShaderInfoLog(id, length, &length, message);
		
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message << std::endl;
		
		glDeleteShader(id);
		
		return 0;
	}
	
	return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glCall(glAttachShader(program, vs));
	glCall(glAttachShader(program, fs));
	
	glCall(glLinkProgram(program));
	
	glCall(glValidateProgram(program));
	
	glCall(glDeleteShader(vs));
	glCall(glDeleteShader(fs));
	
	return program;
}

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
		-0.5f, -0.5f, // 0
		 0.5f, -0.5f, // 1
		 0.5f, 0.5f, // 2
		-0.5f, 0.5f // 3
	};
	
	// this is our index buffer
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};
	
	// vertex array object
	unsigned int vao;
	glCall(glGenVertexArrays(1, &vao));
	glCall(glBindVertexArray(vao));
	
	unsigned int buffer;
	glCall(glGenBuffers(1, &buffer));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	glCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
	
	glCall(glEnableVertexAttribArray(0));
	glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0)); // this line of code links the 'buffer' to the 'vao'...
	
	// index buffer object (aka, ibo)
	unsigned int ibo;
	glCall(glGenBuffers(1, &ibo));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));
	
	std::string vs = readShaderFile("vertexShader.shader");
	std::string fs = readShaderFile("fragmentShader.shader");
	
	unsigned int shader = createShader(vs, fs);
	glCall(glUseProgram(shader));
	
	glCall(int location = glGetUniformLocation(shader, "u_Color"));
	ASSERT(location != -1);
	glCall(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f));
	
	// here we are un-binding everything
	glCall(glBindVertexArray(0));
	glCall(glUseProgram(0));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	
	float r = 0.0f;
	float increment = 0.05f;
	
	std::cout << glGetString(GL_VERSION) << std::endl;
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
		
        /* Render here */
        glCall(glClear(GL_COLOR_BUFFER_BIT));
        	
        // bind out shader
        glCall(glUseProgram(shader));
        
        // set up our uniforms
        glCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));
        
        // we bind our vertex buffer
        //~ glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        
        // we set up the layout of that buffer
        //~ glCall(glEnableVertexAttribArray(0));
		//~ glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
		
		glCall(glBindVertexArray(vao));
		
		// we bind our index buffer
		glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        	
		// this is our draw call for drawing our square (that is made up of two triangles)
        glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        
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
    
    glCall(glDeleteProgram(shader));

    glfwTerminate();
    return 0;
}
