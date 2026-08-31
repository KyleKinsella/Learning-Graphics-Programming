#include "Texture.h"

Texture::Texture(const std::string path) : m_textureId(0), m_buffer(nullptr), m_width(0), m_height(0), m_bitsPerPixel(0) {
	stbi_set_flip_vertically_on_load(true);
	m_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bitsPerPixel, 4);
	
	glGenTextures(1, &m_textureId);
	glBindTexture(GL_TEXTURE_2D, m_textureId);
	
	// settings for our texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // S and T are the same as X and Y but for textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	// send the data to our GPU vRAM
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	if (m_buffer)
		stbi_image_free(m_buffer);
}

Texture::~Texture() {
	glDeleteTextures(1, &m_textureId);
}

void Texture::bindTexture(unsigned int slot) const {
	//~ std::cout << "binding texture: " << slot << std::endl;
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}
