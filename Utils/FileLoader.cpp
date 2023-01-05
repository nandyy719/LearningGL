#include "FileLoader.hpp"
std::string loadFromFile(const std::string& filePath) {
	std::ifstream in(filePath);
	std::stringstream ss;
	ss << in.rdbuf();
	return ss.str();
}