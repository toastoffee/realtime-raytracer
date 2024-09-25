/**
  ******************************************************************************
  * @file           : texture.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/25
  ******************************************************************************
  */


#include "texture2d.hpp"
#include "math_tool.hpp"

Texture2D::Texture2D(unsigned char *data, int w, int h) :
    m_w(w), m_h(h) {

    m_data = (unsigned char *)malloc(w * h * 4);
    memcpy(m_data, data, w * h * 4);
}

Color Texture2D::getColor(int x, int y) const {
    int idx = y * m_w + x;

    return {
        m_data[idx * 4 + 0],
        m_data[idx * 4 + 1],
        m_data[idx * 4 + 2],
        m_data[idx * 4 + 3]
    };
}

Color Texture2D::Sample(float x, float y) const {
    int x_idx = static_cast<int>(x * (float)m_w);
    int y_idx = static_cast<int>(y * (float)m_h);
    x_idx = MathTool::Clamp(x_idx, 0, m_w);
    y_idx = MathTool::Clamp(y_idx, 0, m_h);

    return getColor(x_idx, y_idx);
}
