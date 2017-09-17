#include "textures.h"
#include <shader.h>

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

	//create texture
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//load image
	int width, height, nrChannels;
	unsigned char *data = stbi_load("totoro.png", &width, &height, &nrChannels, 0);
	
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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
	int indices[] = {
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

	//unbind vao
	glBindVertexArray(0);

	Shader shader("textures.vert","textures.frag");
	shader.use();
}

void core::Textures::render()
{
	//glBindTexture(GL_TEXTURE_2D, _texture);
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


int main()
{
	Textures tex("textures");
	tex.init();
	return 1;
}
