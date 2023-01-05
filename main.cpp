#include<iostream>
#include "Window.hpp"
#include "FileLoader.hpp"
#include "Shader.hpp"


int main(int argc, char** argv) {

	Window win(800, 800, "LEARNINGGL");
	std::cout << "OPENGL VERSION: " << glGetString(GL_VERSION) << '\n';

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	GLfloat positions[] = {
		0.0f, 0.5f,
		-0.5f,-0.5f, 
		0.5f, -0.5f

	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

	Shader sh(loadFromFile("C:/Users/nandh/OneDrive/Desktop/Workspace/CandCppProjects/LearningGL/Resources/vertex_shader.glsl"), loadFromFile("C:/Users/nandh/OneDrive/Desktop/Workspace/CandCppProjects/LearningGL/Resources/fragment_shader.glsl"));
	sh.bind();
	while (win.isOpen()) {
		win.clear(0.3f, 0.4f, 0.5f, 0.69f);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		win.swapBuffers();
		win.listenForEvents();
	}
	return 0;
}