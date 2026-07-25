#pragma once

#include "../Renderer/renderer.h"

class Texture {
public:
	Texture(const std::string& path);
	~Texture();

	// slot is an optional parameter, so if we dont pass anything the value will be zero by default!
	void bind(unsigned int slot = 0) const;
	void unBind() const;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
	inline int getBitsPerPixel() const { return m_BPP; }
	
private:
	unsigned int m_RendererId;
	std::string m_filePath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_BPP; // BPP = bits per pixel
};
