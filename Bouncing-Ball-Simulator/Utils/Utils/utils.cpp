#include "utils.h"

const std::vector<std::string> Utils::getTextures(std::string textures) {
	std::vector<std::string> files;
	for (const auto& entry : std::filesystem::directory_iterator(textures)) {				
		files.push_back(entry.path().string());
	}
	return files;
}
