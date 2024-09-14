/**
  ******************************************************************************
  * @file           : render_window.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/13
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_RENDER_WINDOW_HPP
#define REALTIME_RAYTRACER_RENDER_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

class RenderWindow {
private:
    GLFWwindow *m_wnd;
    ImVec4 m_clearColor;
    int m_wndSizeX, m_wndSizeY;

    bool init();
    void close();
    bool isWndShouldClose();

public:

    RenderWindow(int wndSizeX, int wndSizeY);
    ~RenderWindow();

    bool BeginWindow();
    void EndWindow();
};


#endif //REALTIME_RAYTRACER_RENDER_WINDOW_HPP
