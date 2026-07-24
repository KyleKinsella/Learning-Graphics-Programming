#include "VertexArray.h"
#include "renderer.h"

VertexArray::VertexArray() {
	glCall(glGenVertexArrays(1, &m_RendererId));
}

VertexArray::~VertexArray() {
	glCall(glDeleteVertexArrays(1, &m_RendererId))
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const {
	bind();
	vb.bind();
	
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	
	// set-up our layout for our buffer
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		glCall(glEnableVertexAttribArray(i));
		glCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset));
		
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const {
	glCall(glBindVertexArray(m_RendererId));
}

void VertexArray::unBind() const {
	glCall(glBindVertexArray(0));
}
