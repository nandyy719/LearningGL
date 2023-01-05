# CMakeList.txt : CMake project for LearningGL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.1...3.17)

project (LearningGL VERSION 0.1 DESCRIPTION "Toy porject to learn opengl and graphics with C++.")

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Utils")
# Add source to this projec
add_executable (LearningGL main.cpp Window.cpp Window.hpp Shader.cpp Shader.hpp "Mesh.cpp")
target_link_libraries(LearningGL glfw GLEW::GLEW OpenGL::GL glm lib_utils)

# TODO: Add tests and install targets if needed.
