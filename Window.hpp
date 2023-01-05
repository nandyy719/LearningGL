#ifndef WINDOW_H
#define WINDOW_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>

typedef unsigned int uint;

struct Window {
private:
	GLFWwindow* m_Win;
public:
	Window(uint w, uint h, const std::string& title, int gl_version_major = 3, int gl_version_minor = 3);
	void clear(float r, float g, float b, float a);
	bool isOpen();
	void swapBuffers();
	void listenForEvents();

	~Window();
};

#endif