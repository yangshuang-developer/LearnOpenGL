#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
public:
	Shader();
	Shader(std::string vertfile, std::string fragfile);
	~Shader();

protected:
	GLuint _programID;

public:
	//init
	void load(std::string vertfile,std::string fragfile);

	//functions
	void use();
	void setUniformal(const std::string &name,int value);
	void setUniformal(const std::string &name, float value);
	void setUniformal(const std::string &name, bool value);
	void setUniformal(const std::string &name, glm::mat4 value);
};

