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

Canvas::Canvas() : m_width(0), m_height(0), m_tex(0) { }

Canvas::~Canvas() = default;

void Canvas::UpdateTex(unsigned char* pixels, int w, int h) {

    // Create a OpenGL texture identifier
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

void Canvas::Render() const {
    ImGui::Begin("Canvas");
    ImGui::Text("Avg fps: %.3f", ImGui::GetIO().Framerate);
    float canvasWidth = ImGui::GetWindowSize().x;
    float hwRatio = (float)m_height / (float)m_width;
    ImGui::Image((void*)(intptr_t)m_tex, ImVec2(canvasWidth, canvasWidth * hwRatio));
    ImGui::End();
}


