# OpenGL Notes

## Set up project
### Code::Blocks
- Compiler settings → Search directories: add `Include` directory with GLFW, glad and KHR folders
- Linker settings: `-lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl`

### CLion
`CMakeLists.txt`:
~~~
add_executable(Test main.cpp glad.c)

include_directories("/home/jonas/Dokumente/OpenGL/Libraries/Include")
target_link_libraries(project_name glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)
~~~
