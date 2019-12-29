#include "application.h"

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
		load();
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
	void Application::load()
	{
		//override
	}
	void Application::render()
	{
		//override
	}
	inline std::string Application::getCurrentDirectory()
	{
		//char buff[255];
		//int dwRet = -1;
		//dwRet = GetCurrentDirectoryA(BUFSIZE, (LPSTR)buff);

		//if (dwRet == 0)
		//{
		//	printf("GetCurrentDirectory failed (%d)\n", GetLastError());
		//	return std::string();
		//}
		//return std::string(buff);
		return "";
	}
}