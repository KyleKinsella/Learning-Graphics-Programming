#pragma once

#include "../VertexBuffer/VertexBuffer.h"
//~ #include "../VertexBufferLayout/VertexBufferLayout.h"

// forward declare ing class... (due to domino of renderer includes)
class VertexBufferLayout;

class VertexArray {
public:
	VertexArray();
	~VertexArray();
	
	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const;
	void bind() const;
	void unBind() const;
private:	
	unsigned int m_RendererId;
};
