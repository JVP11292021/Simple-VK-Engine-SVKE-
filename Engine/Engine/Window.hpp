#ifndef VLE_WINDOW_H
#define SVKEVLE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <cinttypes>
#include <string>

#include "defs.hpp"

VLE_NS_B

class EngineWindow {
public:
	explicit EngineWindow(std::int32_t w, std::int32_t h, std::string t);
	~EngineWindow();

	EngineWindow(const EngineWindow&) = delete;
	EngineWindow& operator=(const EngineWindow&) = delete;

	inline bool shouldClose() { return glfwWindowShouldClose(this->_win); }

private:
	void init();

private:
	GLFWwindow* _win;

	const std::int32_t _width;
	const std::int32_t _height;
	std::string _title;
};

VLE_NS_E

#endif // VLE_WINDOW_H