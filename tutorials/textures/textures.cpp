#include "textures.h"
#include <windows.h> 
#define BUFSIZE MAX_PATH

using namespace core;

core::Textures::Textures(std::string name, int width, int height):
	Application(name, width, height)
{

}
std::string Textures::getCurrentDirectory()
{
	char buff[BUFSIZE];
	int dwRet = -1;
	dwRet = GetCurrentDirectory(BUFSIZE, buff);

	if (dwRet == 0)
	{
		printf("GetCurrentDirectory failed (%d)\n", GetLastError());
		return std::string();
	}
	return std::string(buff);
}

void core::Textures::feed()
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
		0.5f,  0.5f, 0.0f,	1.0f, 0.0f, 0.0f,   1.0f, 1.0f,  
		0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,   1.0f, 0.0f,  
		-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,   0.0f, 0.0f,  
		-0.5f,  0.5f, 0.0f,	1.0f, 1.0f, 0.0f,   0.0f, 1.0f    
	};
	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};
	//vao
	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);
	//VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//EBO
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Attr
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	_shader = std::make_unique<Shader>("textures.vert", "textures.frag");
	
	//unbind vao
	glBindVertexArray(0);
	_shader->use();

	_shader->setUniformal("u_tex0",0);
	_shader->setUniformal("u_tex1", 1);
		
}

void core::Textures::render()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, _texture1);

	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


int main()
{
	Textures tex("textures");
	tex.init();
	return 1;
}
