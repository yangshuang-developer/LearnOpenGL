#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <functional>

namespace core {
	class application
	{
	public:
		application(std::string name = "LearnOpenGL",int w = 800,int h = 600);
		virtual ~application();
		virtual void init();
		void setFramebufferSizeCallback(std::function<void(int width, int height)> = nullptr);
		void setProcessInputCallback(std::function<void(int width, int height)> = nullptr);
	// function 
	private:
		struct{
			std::function<void(GLFWwindow*, int, int)> framebufferSizeCallback;
			std::function<void(GLFWwindow*)> processInputCallback;
		} _callbacks;


	protected:
		int _w;
		int _h;
		GLFWwindow* _window;
		std::string _name;
	};
}