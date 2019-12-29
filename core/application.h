#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <iostream>
#include <functional>

namespace core {
	class Application
	{
	public:
		Application(std::string name = "LearnOpenGL",int width = 800,int height = 600);
		virtual ~Application();
		void init();
		virtual void load();
		virtual void render();
		inline std::string getCurrentDirectory();
	// function 
	protected:

		static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

		virtual void processInput();

	protected:
		int _width;
		int _height;
		GLFWwindow* _window;
		std::string _name;
	};
}