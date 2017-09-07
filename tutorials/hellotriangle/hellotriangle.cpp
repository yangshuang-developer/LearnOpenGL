#include "hellotriangle.h"

using namespace core;

HelloTriangle::HelloTriangle(std::string name, int width, int height) :
	Application(name, width, height)
{
}

void HelloTriangle::feed()
{
	//set up triangle data
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	//VAO
	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind vao
	glBindVertexArray(0);

	//vertex shader	
	std::string vert = {
		"#version 330 core\n"
		"layout (location = 0) in vec3 a_pos;"
		"void main(){"
		"gl_Position = vec4(a_pos,1.0);"
		"}"
	};
	GLint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertSource = {
		vert.c_str()
	};
	glShaderSource(vertexShader, 1, &vertSource, NULL);
	glCompileShader(vertexShader);
	int  success;
	char infoLog[512];
	//check
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//fragment shader
	std::string frag = {
		"#version 330 core\n"
		//"out vec4 FragColor;"
		"void main()"
		"{"
		//"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
		"gl_FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
		"} "
	};
	GLint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragSource = {
		frag.c_str()
	};
	glShaderSource(fragmentShader, 1, &fragSource, NULL);
	glCompileShader(fragmentShader);
	//check
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//create program
	GLint _shaderProgram;
	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, vertexShader);
	glAttachShader(_shaderProgram, fragmentShader);

	//link prigram
	glLinkProgram(_shaderProgram);
	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}
	glUseProgram(_shaderProgram);
	//clean
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void core::HelloTriangle::render()
{
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main()
{
	HelloTriangle win("hello triangle");
	win.init();
}

