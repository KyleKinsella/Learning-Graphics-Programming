#include "IndexBuffer.h"
#include "renderer.h"

// initialize list for 'm_Count(count)'
IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_Count(count) {
	
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	
	glCall(glGenBuffers(1, &m_RendererId));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
	glCall(glDeleteBuffers(1, &m_RendererId));
}

void IndexBuffer::bind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
}

void IndexBuffer::unBind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
