#include "Shader.hpp"
#include<iostream>
#include<memory>
Shader::Shader(const std::string& vs, const std::string& fs) {
	prog_id = glCreateProgram();
	if (prog_id == 0) {
		std::cout << "Failed to create prgoram\n";
		return;
	}
	GLuint vertex_shader = compileShader(vs, GL_VERTEX_SHADER);
	GLuint frag_shader = compileShader(fs, GL_FRAGMENT_SHADER);

	glAttachShader(prog_id, vertex_shader);
	glAttachShader(prog_id, frag_shader);
	glLinkProgram(prog_id);
	handleLinkErrors();

	glDetachShader(prog_id, vertex_shader);
	glDetachShader(prog_id, frag_shader);

	glDeleteShader(vertex_shader);
	glDeleteShader(frag_shader);

	
}
GLuint Shader::getProgram() {
	return prog_id;
}
GLuint Shader::compileShader(const std::string& shader_src, GLenum shader_type) {
	GLuint shader_id = glCreateShader(shader_type);
	if (shader_id == 0) {
		std::cout << "Faile to create shader\n";
		return 0;
	}
	const char* src = shader_src.c_str();
	glShaderSource(shader_id, 1, &src, nullptr);
	glCompileShader(shader_id);
	handleCompileErrors(shader_id);
	return shader_id;
}
void Shader::handleCompileErrors(GLuint shader_id) {
	GLint status;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint len;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &len);
		char* msg = new char[len];
		std::unique_ptr<GLchar[]> ptr(msg);
		glGetShaderInfoLog(shader_id, len, nullptr, msg);
		std::cout << "Failed to compile shader: " << msg << '\n';
		glDeleteShader(shader_id);
	}
}
void Shader::handleLinkErrors() {
	GLint status;
	glGetProgramiv(prog_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint len;
		glGetProgramiv(prog_id, GL_INFO_LOG_LENGTH, &len);
		char* msg = new char[len];
		std::unique_ptr<GLchar[]> ptr(msg);
		glGetProgramInfoLog(prog_id, len, nullptr, msg);
		std::cout << "Failed to link program: " << msg << '\n';
	}
}
void Shader::validate() {
	glValidateProgram(prog_id);
	GLint status;
	glGetProgramiv(prog_id, GL_VALIDATE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint len;
		glGetProgramiv(prog_id, GL_INFO_LOG_LENGTH, &len);
		char* msg = new char[len];
		std::unique_ptr<GLchar[]> ptr(msg);
		glGetProgramInfoLog(prog_id, len, nullptr, msg);
		std::cout << "Failed to validate program: " << msg << '\n';
	}
}

void Shader::bind() {
	glUseProgram(prog_id);
}
Shader::~Shader() {
	glDeleteProgram(prog_id);
}