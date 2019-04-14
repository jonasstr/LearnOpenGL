cmake_minimum_required(VERSION 3.13)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test glad.c header.h src/shader.h 02-shaders/03_move_triangle.cpp)

include_directories("/home/jonas/Dokumente/OpenGL/Libraries/Include")
target_link_libraries(Test glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)