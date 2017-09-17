#pragma once

#include <application.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace core {
	class Textures :public Application {
	public:
		Textures(std::string name, int width = 800, int height = 600);
		virtual void feed() override;
		virtual void render();
		inline std::string getCurrentDirectory();
	protected:
		//VAO
		GLuint _VAO;
		//program
		GLint _shaderProgram;
		GLuint _texture;
	};
}
