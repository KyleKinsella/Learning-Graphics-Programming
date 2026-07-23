#include "VertexBuffer.h"
#include "renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	glCall(glGenBuffers(1, &m_RendererId));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
	glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
	glCall(glDeleteBuffers(1, &m_RendererId));
}

void VertexBuffer::bind() const {
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
}

void VertexBuffer::unBind() const {
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
