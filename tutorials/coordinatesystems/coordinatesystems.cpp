#include<random>

#include "coordinatesystems.h"



core::Coordinatesystems::Coordinatesystems(std::string name, int width, int height)
	:Application(name, width, height)
{
}

void core::Coordinatesystems::load()
{
	//load image
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("totoro.png", &width, &height, &nrChannels, 0);

	if (data)
	{
		//create texture
		glGenTextures(1, &_texture0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture0);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	//release the image data
	stbi_image_free(data);

	data = stbi_load("wuliannan.png", &width, &height, &nrChannels, 0);

	if (data)
	{
		//create texture
		glGenTextures(1, &_texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, _texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	//release the image data
	stbi_image_free(data);

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	//vao
	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);
	//VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Attr
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	_shader = std::make_unique<Shader>("coordinatesystems.vert", "coordinatesystems.frag");

	//unbind vao
	glBindVertexArray(0);
	_shader->use();

	_shader->setUniformal("u_tex0", 0);
	_shader->setUniformal("u_tex1", 1);
	//glm::mat4 model;
	//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));

	glEnable(GL_DEPTH_TEST);

	std::default_random_engine e;
	std::normal_distribution<> n(1, 0.3);
	
#define POS_NUM 10
	_posList.reserve(POS_NUM);

	for (size_t i = 0; i < POS_NUM; i++)
	{
		glm::vec3 point;
		for (size_t v = 0; v < 3; v++)
		{
			point.x = (float)std::lroundf(n(e));
			point.y = (float)std::lroundf(n(e));
			point.z = (float)std::lroundf(n(e));
		}
		_posList.push_back(point);
	}
}

void core::Coordinatesystems::render()
{
	// create transformations
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, _texture1);

	glm::mat4 view;
	glm::mat4 proj;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	proj = glm::perspective(glm::radians(45.0f), (float)_width / (float)_height, 0.1f, 100.0f);
	for (auto pos: _posList)
	{
		glm::mat4 model;
		model = glm::translate(model,pos);
		model = glm::rotate(model, (float)glfwGetTime()*(pos.x + pos.y+pos.z)/3.0f, glm::vec3(0.3f, sinf((float)glfwGetTime()* 0.6f), 0.5f));
		_shader->setUniformal("u_model", model);

		_shader->setUniformal("u_view", view);
		_shader->setUniformal("u_proj", proj);

		glBindVertexArray(_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}


int main()
{
	core::Coordinatesystems demo("Coordinatesystems");
	demo.init();
	return 1;
}