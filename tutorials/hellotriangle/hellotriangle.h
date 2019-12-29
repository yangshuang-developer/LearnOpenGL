#pragma once
#include <application.h>

namespace core {
	class HelloTriangle :public Application {
	public:
		HelloTriangle(std::string name, int width = 800, int height = 600);
		virtual void load() override;
		virtual void render();

	protected:
		//VAO
		GLuint _VAO;
		//program
		GLint _shaderProgram;
	};
}

