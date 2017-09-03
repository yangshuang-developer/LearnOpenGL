#include "application.h"

namespace core {
	application::application(std::string name,int w,int h):
		_name(name),
		_w(w),
		_h(h),
		_window(nullptr)
		{

		//todo
		_callbacks.framebufferSizeCallback = [=](GLFWwindow* window, int w,int h) {
				glViewport(0, 0, w, h);
			};
		_callbacks.processInputCallback = [=](GLFWwindow *window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		};
		init();

	}
	application::~application(){
		if (_window)
		{
			glfwTerminate();
		}
	}
	void application::init() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		_window = glfwCreateWindow(_w, _h, _name.c_str(), NULL, NULL);
		if (_window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(_window);
		//glfwSetFramebufferSizeCallback(_window,*_callbacks.framebufferSizeCallback.target<GLFWframebuffersizefun>());
		//glfwSetFramebufferSizeCallback(_window, std::bind(_callbacks.framebufferSizeCallback, this));
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}

		glViewport(0, 0, _w, _h);
		while (!glfwWindowShouldClose(_window))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			if (_callbacks.processInputCallback)
			{
				_callbacks.processInputCallback(_window);
			}
			glfwSwapBuffers(_window);
			glfwPollEvents();
		}
	}
	void application::setFramebufferSizeCallback(std::function<void(int width, int height)>)
	{
	}
	void application::setProcessInputCallback(std::function<void(int width, int height)>)
	{
	}
}