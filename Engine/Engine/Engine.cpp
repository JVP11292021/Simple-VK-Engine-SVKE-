#include <iostream>

#include "Device.hpp"
#include "defs.hpp"
#include "Window.hpp"
#include "SwapChain.hpp"
#include "Pipeline.hpp"

#include <memory>
#include <stdexcept>

class FirstApp {
public:
	static constexpr std::int32_t WIDTH = 800;
	static constexpr std::int32_t HEIGHT = 600;

	FirstApp() {
		this->createPipelineLayout();
		this->createPipelineLayout();
		this->createCommandBuffers();
	}

	~FirstApp() {
		vkDestroyPipelineLayout(this->device.device(), pipelineLayout, nullptr);
	}

	FirstApp(const FirstApp&) = delete;
	void operator=(const FirstApp&) = delete;

	void run() {
		while (!this->win.shouldClose()) {
			glfwPollEvents();
		}
	}
private:
	void createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;

		if (vkCreatePipelineLayout(this->device.device(), &pipelineLayoutInfo, nullptr, &this->pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create pipeline layout");
		}
	}

	void createPipeline() {
		auto pipelineConfig = vle::Pipeline::defaultPipelineConfigInfo(this->swapChain.width(), this->swapChain.height());
		pipelineConfig.renderPass = this->swapChain.getRenderPass();
		pipelineConfig.pipelineLayout = this->pipelineLayout;
		this->pipeline = std::make_unique<vle::Pipeline>(device, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", vle::Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT));
	}

	void createCommandBuffers() {

	}

	void drawFrame() {

	}

private:
	vle::EngineWindow win{WIDTH, HEIGHT, "Hello Vulkan"};
	vle::EngineDevice device{ win };
	vle::EngineSwapChain swapChain{ device, win.getExtent() };
	std::unique_ptr<vle::Pipeline> pipeline;
	VkPipelineLayout pipelineLayout;
	std::vector<VkCommandBuffer> commandBuffers;
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


