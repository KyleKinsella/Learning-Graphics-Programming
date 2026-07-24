#include "renderer.h"

#include <iostream>

// clear all of our errors 
void glClearError() {
	while (glGetError() != GL_NO_ERROR);
}

// then we check to see if we have found any errors, the errors are coming from the below function:
bool glLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << ":" << line << std::endl;
		return false;
	}
	
	return true;
}
