#ifndef SHADER_H
#define SHADER_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
struct Shader {
private:
	GLuint prog_id = 0;
	void handleCompileErrors(GLuint shader_id);
	void handleLinkErrors();
	void validate();
	GLuint compileShader(const std::string& shader_src, GLenum shader_type);
public:
	Shader(const std::string& vs, const std::string& fs);
	GLuint getProgram();
	
	void bind();

	~Shader();

};
#endif