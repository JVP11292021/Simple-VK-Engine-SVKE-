#include "Window.hpp"

VLE_NS_B

EngineWindow::EngineWindow(std::int32_t w, std::int32_t h, std::string t) 
	: _width(w), _height(h), _title(t)
{
	this->init();
}

EngineWindow::~EngineWindow() {
	glfwDestroyWindow(this->_win);
	glfwTerminate();
}

void EngineWindow::init() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->_win = glfwCreateWindow(this->_width, this->_height, this->_title.c_str(), nullptr, nullptr);

}

VLE_NS_E