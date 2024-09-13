cmake_minimum_required(VERSION 3.27)

# project name
project(realtime_raytracer)

set(CMAKE_CXX_STANDARD 11)

# include glad header files
include_directories(glad/include)

# 包含glfw头文件
include_directories(/opt/homebrew/Cellar/glfw/3.4/include)
# 链接glfw库
link_directories(/opt/homebrew/Cellar/glfw/3.4/lib)

include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src
                                    ${PROJECT_SOURCE_DIR}/third_party
)


add_executable(realtime_raytracer main.cpp
                glad/src/glad.c

                third_party/stbi/stb_image.cpp
                third_party/imgui/imgui.cpp
                third_party/imgui/imgui_draw.cpp
                third_party/imgui/imgui_tables.cpp
                third_party/imgui/imgui_widgets.cpp
                third_party/imgui/imgui_demo.cpp

                third_party/imgui/backends/imgui_impl_glfw.cpp
                third_party/imgui/backends/imgui_impl_opengl3.cpp

                src/wnd/imgui_wnd.cpp
                src/wnd/imgui_wnd.h
                src/wnd/imgui_pixel_renderer.cpp
                src/wnd/imgui_pixel_renderer.h
                src/wnd/file_helper.cpp
                src/wnd/file_helper.h
                src/math/vec3.cpp
                src/math/vec3.hpp
        src/math/ray.cpp
        src/math/ray.hpp
)

target_link_libraries(
        ${PROJECT_NAME}
        glfw
)