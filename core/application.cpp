#include "Application.h"


namespace core {
	Application::Application(std::string name,int width,int height):
		_name(name),
		_width(width),
		_height(height),
		_window(nullptr)
		{
			//init();
		}
	Application::~Application(){
		if (_window)
		{
			glfwTerminate();
		}
	}
	void Application::framebufferSizeCallback(GLFWwindow * window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	void Application::processInput()
	{
		if (_window)
		{
			if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(_window, true);
		}
	}
	void Application::init() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		_window = glfwCreateWindow(_width, _height, _name.c_str(), NULL, NULL);
		if (_window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(_window);
		
		glfwSetFramebufferSizeCallback(_window,framebufferSizeCallback);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}

		glViewport(0, 0, _width, _height);
		feed();
		while (!glfwWindowShouldClose(_window))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			processInput();
			render();
			glfwSwapBuffers(_window);
			glfwPollEvents();
		}
	}
	void Application::feed()
	{
		std::cout << "application feed invoke" << std::endl;
	}
	void Application::render()
	{
		//override
	}
}