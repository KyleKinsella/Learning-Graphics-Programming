#pragma once

#include "../vendors/stb/stb_image.h"

//~ #include <string>

//~ #include "../glad/include/glad/glad.h"
//~ #include <GLFW/glfw3.h>

#include "../Everyone/all.h"

class Texture {
public:
	Texture(const std::string path);
	~Texture();
	
	void bindTexture(unsigned int slot = 0) const;
	
private:
	unsigned int m_textureId;
	unsigned char* m_buffer;
	int m_width, m_height, m_bitsPerPixel;
};
