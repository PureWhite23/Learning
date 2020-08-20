#ifndef _SHADER_S_H
#define _SHADER_S_H
#include<iostream>
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr)
	{
		std::string vertexCode;
		std::string fragmentCode;
		std::string geometryCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		std::ifstream gShaderFile;

		try
		{
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;

			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			vShaderFile.close();
			fShaderFile.close();

			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();

			if (geometryPath != nullptr)
			{
				gShaderFile.open(geometryPath);
				std::stringstream gShaderStream;
				gShaderStream << gShaderFile.rdbuf();
				gShaderFile.close();
				geometryCode = gShaderStream.str();
			}
		}
		catch (const std::exception&)
		{
			std::cout << "can't open file" << std::endl;		
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fshaderCode = fragmentCode.c_str();

		int geometry;

		int vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		int fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment,1,&fshaderCode,NULL);
		glCompileShader(fragment);

		if (geometryPath != nullptr)
		{
			const char* gShaderCode = geometryCode.c_str();
			geometry = glCreateShader(GL_GEOMETRY_SHADER);
			glCompileShader(geometry);
		}

		ID = glCreateProgram();
		glAttachShader(ID,vertex);
		glAttachShader(ID,fragment);
		if (geometryPath != nullptr)
		{
			glAttachShader(ID,geometry);
		}
		glLinkProgram(ID);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		if (geometryPath != nullptr)
		{
			glDeleteShader(geometry);
		}
	}
	void use()
	{
		glUseProgram(ID);
	}
};
#endif