#pragma once

#include <memory>

#include <application.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <shader.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace core {
	class Coordinatesystems :public Application {
	public:
		Coordinatesystems(std::string name, int width = 800, int height = 600);
		virtual void load() override;
		virtual void render();

		virtual ~Coordinatesystems() {
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
		std::vector<glm::vec3> _posList;
	};
}
