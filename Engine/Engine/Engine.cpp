#include <iostream>

#include "Device.hpp"
#include "defs.hpp"
#include "Window.hpp"
#include "Pipeline.hpp"

class FirstApp {
public:
	static constexpr std::int32_t WIDTH = 800;
	static constexpr std::int32_t HEIGHT = 600;

	void run() {
		while (!this->win.shouldClose()) {
			glfwPollEvents();
		}
	}
private:
	vle::EngineWindow win{WIDTH, HEIGHT, "Hello Vulkan"};
	vle::EngineDevice device{ win };
	vle::Pipeline pipeline{ device, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", vle::Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
};

int main() {
	FirstApp app;
	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


