# version
cmake_minimum_required(VERSION 3.27)

# project name
project(realtime_raytracer)

# c++ standard
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/third_party)
include_directories(${PROJECT_SOURCE_DIR}/third_party/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/glfw/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(third_party/glfw/lib)

add_executable(realtime_raytracer main.cpp

        # glad
        third_party/glad/src/glad.c

        # imgui
        third_party/imgui/imgui.cpp
        third_party/imgui/imgui_draw.cpp
        third_party/imgui/imgui_tables.cpp
        third_party/imgui/imgui_widgets.cpp
        third_party/imgui/imgui_demo.cpp
        third_party/imgui/backends/imgui_impl_glfw.cpp
        third_party/imgui/backends/imgui_impl_opengl3.cpp

        # src
        src/vec3.cpp
        src/vec3.hpp
        src/ray.cpp
        src/ray.hpp
        src/render_window.cpp
        src/render_window.hpp
        src/color.cpp
        src/color.hpp
        src/canvas.cpp
        src/canvas.hpp
        src/camera.cpp
        src/camera.hpp
        src/math_tool.cpp
        src/math_tool.hpp
        src/path_tracer.cpp
        src/path_tracer.hpp
        src/sphere.cpp
        src/sphere.hpp
        src/object.cpp
        src/object.hpp
)

target_link_libraries(${PROJECT_NAME} glfw)