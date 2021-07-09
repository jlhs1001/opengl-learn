#pragma once
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "scene.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


class Jenjin {
	bool initialScene = true;

	Scene* currentScene;
	unsigned int screenWidth = 0;
	unsigned int screenHeight = 0;

	GLFWwindow* window;

	char* title;
public:
	void Initialize(unsigned int width, unsigned int height, const char* title) {
		// GLFW: Initialization and configuration
		// --------------------------------------
		glfwInit();
		// hint glfw version (3.3)
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		// If apple, set openGL forward compatable to true.
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		GLFWwindow* wnd = glfwCreateWindow(screenWidth, screenHeight, title, nullptr, nullptr);
		if (!wnd)
		{
			std::cout << "\033[1;31mFatal: Error initializing window.\033[0m\n";
			glfwTerminate();
			exit(-1);
		}
		this->window = wnd;
		std::cout << "jenjin by liam seewald" << std::endl;

		glfwMakeContextCurrent(this->window);
		if (glewInit() != GLEW_OK)
			std::cout << "Fatal: Error initializing glew" << std::endl;
		
		std::cout << glGetString(GL_VERSION) << std::endl;

		// configure global opengl state
		// -----------------------------
		glEnable(GL_DEPTH_TEST);

		// callback functions
		
	}

	void loadScene(Scene* scene) {
		this->currentScene = scene;

		
	}
};