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


Texture2D::Texture2D(unsigned char *data, int w, int h, int channels) :
    m_w(w), m_h(h), m_channels(channels) {

    m_data = (unsigned char *)malloc(w * h * channels);
    memcpy(m_data, data, w * h * channels);
}


Color Texture2D::getColor(int x, int y) const {
    int idx = y * m_w + x;

    if(m_channels == 3) {
        return {
                m_data[idx * 3 + 0],
                m_data[idx * 3 + 1],
                m_data[idx * 3 + 2]
        };
    } else if(m_channels == 4) {
        return {
                m_data[idx * 4 + 0],
                m_data[idx * 4 + 1],
                m_data[idx * 4 + 2],
                m_data[idx * 4 + 3]
        };
    }

    // return Magenta
    return {1.0f, 0.0f, 1.0f};
}

Color Texture2D::Sample(double x, double y) const {
    int x_idx = static_cast<int>(x * ((float)m_w - 0.1f));
    int y_idx = static_cast<int>(y * ((float)m_h - 0.1f));
    x_idx = MathTool::Clamp(x_idx, 0, m_w - 1);
    y_idx = MathTool::Clamp(y_idx, 0, m_h - 1);

    return getColor(x_idx, y_idx);
}