#include "Texture.h"

#include "../vendor/stb/stb_image.h"

Texture::Texture(const std::string& path) : m_RendererId(0), m_filePath(path), m_localBuffer(nullptr), m_width(0), m_height(0), m_BPP(0) {
	
	// this flips our texture vertically, so our texture is upside down
	// why? opengl expects our pixels to start at the bottom of left and not the top left
	stbi_set_flip_vertically_on_load(1);
	m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
	
	glCall(glGenTextures(1, &m_RendererId));
	glCall(glBindTexture(GL_TEXTURE_2D, m_RendererId));
	
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); // S and T are the same as X and Y but for textures
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	
	glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
	glCall(glBindTexture(GL_TEXTURE_2D, 0)); // wait, we have to unbind here!?
	
	if (m_localBuffer)
		stbi_image_free(m_localBuffer);
}

Texture::~Texture() {
	glCall(glDeleteTextures(1, &m_RendererId));
}

void Texture::bind(unsigned int slot) const {
	glCall(glActiveTexture(GL_TEXTURE0 + slot));
	glCall(glBindTexture(GL_TEXTURE_2D, m_RendererId));
}

void Texture::unBind() const {
	glCall(glBindTexture(GL_TEXTURE_2D, 0));
}
