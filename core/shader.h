#pragma once
#include<glad\glad.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>


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
};

