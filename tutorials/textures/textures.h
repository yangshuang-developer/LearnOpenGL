#pragma once

#include <memory>

#include <application.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <shader.h>

namespace core {
	class Textures :public Application {
	public:
		Textures(std::string name, int width = 800, int height = 600);
		virtual void feed() override;
		virtual void render();
		inline std::string getCurrentDirectory();

		virtual ~Textures() {
			if (_shader)
			{
				delete _shader.release();
			}
		}
	protected:
		//VAO
		GLuint _VAO;
		//program
		std::unique_ptr<Shader> _shader;
		GLuint _texture0;
		GLuint _texture1;

	};
}
