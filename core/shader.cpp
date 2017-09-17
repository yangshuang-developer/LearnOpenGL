#include "shader.h"

Shader::Shader()
{
}

Shader::Shader(std::string vertfile, std::string fragfile)
{
	load(vertfile, fragfile);
}

Shader::~Shader()
{
}

void Shader::load(std::string vertfile, std::string fragfile)
{
	//open and parse vertshader from file
	const char* vertsource = nullptr;
	const char* fragsource = nullptr;
	std::string vertsrc;
	std::string fragsrc;

	std::ifstream file;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try
	{
		std::stringstream buff;
		file.open(vertfile);
		buff << file.rdbuf();
		vertsrc = buff.str();
		vertsource = vertsrc.c_str();
		file.close();

		buff.clear();
		buff.str("");

		file.open(fragfile);
		buff << file.rdbuf();
		fragsrc = buff.str();
		fragsource = fragsrc.c_str();
		file.close();
		
	}
	catch (const std::ifstream::failure e)
	{
		std::cout << "file access error:" << e.what() << std::endl;
	}

	//compile the shader
	GLuint vert, frag;
	int status;
	char log[512];

	//vert shader
	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vertsource, &status);
	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		glGetShaderInfoLog(vert, 512, NULL, log);
		std::cout << "Error:VertexShader -> compile failed! " << log << std::endl;
	}
	//frag shader
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragsource, &status);
	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		glGetShaderInfoLog(frag, 512, NULL, log);
		std::cout << "Error:FragmentShader -> compile failed! " << log << std::endl;
	}
	_programID = glCreateProgram();
	glAttachShader(_programID, vert);
	glAttachShader(_programID, frag);

	//link
	glLinkProgram(_programID);

	glGetProgramiv(_programID, GL_LINK_STATUS, &status);
	if (!status)
	{
		glGetProgramInfoLog(frag, 512, NULL, log);
		std::cout << "Error:Program -> link failed! " << log << std::endl;
	}
	//clear
	glDeleteShader(vert);
	glDeleteShader(frag);
}

void Shader::use()
{
	glUseProgram(_programID);
}

void Shader::setUniformal(const std::string & name, int value)
{
	glUniform1i(glGetUniformLocation(_programID, name.c_str()), value);
}

void Shader::setUniformal(const std::string & name, float value)
{
	glUniform1f(glGetUniformLocation(_programID, name.c_str()), value);
}

void Shader::setUniformal(const std::string & name, bool value)
{
	glUniform1i(glGetUniformLocation(_programID, name.c_str()), (int)value);
}
