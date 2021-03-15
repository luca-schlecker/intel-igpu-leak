cmake_minimum_required(VERSION 3.17)
project(intel-iGPU-leak
  LANGUAGES CXX
  VERSION 0.1.0
)

add_executable(intel-iGPU-leak
  src/main.cpp
)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(intel-iGPU-leak PRIVATE glfw OpenGL::OpenGL GLEW::GLEW)
