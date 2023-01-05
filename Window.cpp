#include "Window.hpp"
#include<iostream>

Window::Window(uint w, uint h, const std::string& title, int gl_version_major, int gl_version_minor) {
	if (!glfwInit()) {
		std::cerr << "FAILED TO INITIALIZE GLFW\n";
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Win = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
	
	if (m_Win == nullptr) {
		std::cerr << "FAILED TO OPEN A GLFW WINDOW\n";
		return;
	}

	glfwMakeContextCurrent(m_Win);

	if (glewInit() != GLEW_OK) {
		std::cerr << "FAILED TO INITIALIZE GLEW!\n";
		return;
	}
	
}
void Window::clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}
bool Window::isOpen() {
	return !glfwWindowShouldClose(m_Win);
}
void Window::swapBuffers() {
	glfwSwapBuffers(m_Win);
}
void Window::listenForEvents() {
	glfwPollEvents();
}
Window::~Window() {
	glfwTerminate();
}