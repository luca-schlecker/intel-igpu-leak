#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <gl/glew.h>

void draw() {
  glClearColor(1, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
  glfwInit();

  auto win = glfwCreateWindow(1280, 720, "title", nullptr, nullptr);

  glfwMakeContextCurrent(win);

  glewInit();

  glfwSetWindowSizeCallback(win, [](GLFWwindow* window, int width, int height) {
    draw();
    glfwSwapBuffers(window);
  });

  while (!glfwWindowShouldClose(win)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(win);
  glfwTerminate();
  return 0;
}
