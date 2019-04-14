cmake_minimum_required(VERSION 3.13)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test src/glad.c src/header.h src/shader.h 03-textures/basic-triangle.cpp)

include_directories("/home/jonas/Dokumente/OpenGL/Libraries/Include")
target_link_libraries(Test glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)