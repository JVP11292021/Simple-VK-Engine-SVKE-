#ifndef VLE_PIPELINE_H
#define VLE_PIPELINE_H

#include <string>
#include <vector>

#include "defs.hpp"

VLE_NS_B

class Pipeline {
public:
	explicit Pipeline(const std::string& vertFilePath, const std::string& fragFilePath);

private:
	static std::vector<char> readFile(const std::string& path);

	void createGfxPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
};

VLE_NS_E

#endif // VLE_PIPELINE_H