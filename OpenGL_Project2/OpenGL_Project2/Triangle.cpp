#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

const char *vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec 3 v_Position;\n"
"void main()\n"
"{\n"
	"gl_Position = vec4(v_Position.x,v_Position.y,v_Position.z,1.0);\n"
"}\0";

const char *fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
	"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main() 
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	GLFWwindow* window = glfwCreateWindow(800,600,"Triangle",NULL,NULL);

	if (window == NULL)
	{
		std::cout<< "Failed to create" << std::endl;
		glfwTerminate();
		return 0;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init" << std::endl;
		return -1;
	}

	//创建shader
	int vertextShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertextShader,1,&vertexShaderSource,NULL);
	glCompileShader(vertextShader);

	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1,&fragmentShaderSource , NULL);
	glCompileShader(fragmentShader);

	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertextShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertextShader);
	glDeleteShader(fragmentShader);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	GLfloat vertices2[] = {
		-0.5f, -0.8f, 0.0f,
		 0.5f, -0.8f, 0.0f,
		 0.0f,  0.2f, 0.0f,
	};

	//创建VAO,VBO
	GLuint VAO, VBO;
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1, &VBO);

	//绑定VAO,VBO
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	//将顶点数组复制到buffer
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	GLuint VAO2, VBO2;
	glGenVertexArrays(2, &VAO2);
	glGenBuffers(2, &VBO2);

	//绑定VAO2,VBO2
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	//将顶点数组复制到buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER,0);
	//glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);		
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//glDeleteVertexArrays(1,&VAO);
	//glDeleteBuffers(1,&VBO);

	glDeleteVertexArrays(2, &VAO2);
	glDeleteBuffers(2, &VBO2);
	glDeleteProgram(shaderProgram);
	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}