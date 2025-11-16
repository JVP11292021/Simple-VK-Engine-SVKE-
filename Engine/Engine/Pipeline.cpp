#include "Pipeline.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

VLE_NS_B

Pipeline::Pipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
	this->createGfxPipeline(vertFilePath, fragFilePath);
}

std::vector<char> Pipeline::readFile(const std::string& path) {
	std::ifstream file(path, std::ios::ate | std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("failed to open file: " + path);
	}

	std::size_t fileSize = static_cast<std::size_t>(file.tellg());
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);

	file.close();
	return buffer;
}

void Pipeline::createGfxPipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
	auto vertCode = this->readFile(vertFilePath);
	auto fragCode = this->readFile(fragFilePath);

	std::cout << "Vertex shader code size: " << vertCode.size() << "\n";
	std::cout << "Fragment shader code size: " << fragCode.size() << "\n";

}

VLE_NS_E