#pragma once

#include "../glad/include/glad/glad.h"
#include <signal.h>

#include "../VertexArray/VertexArray.h"
#include "../IndexBuffer/IndexBuffer.h"
#include "../Shader/Shader.h"

#define ASSERT(x) if (!(x)) raise(x);
#define glCall(x) glClearError();\
	x;\
	ASSERT(glLogCall(#x, __FILE__, __LINE__))
	
void glClearError();
bool glLogCall(const char* function, const char* file, int line);

class Renderer {
public:
	void clear() const;
	void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
