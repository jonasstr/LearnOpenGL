cmake_minimum_required(VERSION 3.13)
project(Test)

set(CMAKE_CXX_STANDARD 14)

# 02: Sine color triangle.
#add_executable(Test lib/glad.c src/header.h src/shader.h src/shader.cpp 02-shaders/x_sine_color.cpp)

# 02: Move triangle.
#add_executable(Test lib/glad.c src/header.h src/shader.h src/shader.cpp 02-shaders/03_move_triangle.cpp)

# 03: Container texture.
#add_executable(Test lib/glad.c src/header.h src/shader.h src/shader.cpp 03-textures/mixed-container.cpp)
add_executable(Test src/glad.c src/header.h src/shader.h src/shader.cpp 03-textures/x_alpha-container.cpp)

include_directories("/home/jonas/Dokumente/OpenGL/Libraries/Include")
target_link_libraries(Test glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)