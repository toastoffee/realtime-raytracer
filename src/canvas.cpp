/**
  ******************************************************************************
  * @file           : canvas.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/14
  ******************************************************************************
  */


#include <glad/glad.h>
#include <imgui/imgui.h>

#include "canvas.hpp"

Canvas::Canvas(int width, int height)
: m_width(width), m_height(height) {
    m_pixels = new Color[width * height];
    m_texData = new unsigned char[width * height * 4];
    m_tex = 0;
}

Canvas::~Canvas() {
    delete[] m_pixels;
}

void Canvas::WriteInPixel(const Color &color, int x, int y) {
    m_pixels[x + y * m_width] = color;
}

void Canvas::UpdateTex() {

    // Load pixel data to tex data
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int idx = i + j * m_width;

            m_texData[idx * 4 + 0] = m_pixels[idx].r8();
            m_texData[idx * 4 + 1] = m_pixels[idx].g8();
            m_texData[idx * 4 + 2] = m_pixels[idx].b8();
            m_texData[idx * 4 + 3] = m_pixels[idx].a8();
        }
    }

    // Create a OpenGL texture identifier
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, m_texData);


}

void Canvas::Render() const {
    ImGui::Begin("Canvas");
    float canvasWidth = ImGui::GetWindowSize().x;
    float hwRatio = (float)m_height / (float)m_width;
    ImGui::Image((void*)(intptr_t)m_tex, ImVec2(canvasWidth, canvasWidth * hwRatio));
    ImGui::End();
}
