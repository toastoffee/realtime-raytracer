/**
  ******************************************************************************
  * @file           : path_tracer.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/17
  ******************************************************************************
  */



#include "path_tracer.hpp"

PathTracer::PathTracer() :
    m_cam(Vec3::zero(), 90.f, 90, 160),
    m_window(1280, 720),
    m_resolutionMaxX(2048), m_resolutionMaxY(2048) {

    m_renderData = new unsigned char[m_resolutionMaxX * m_resolutionMaxY * 4];

    m_camFov = (float)m_cam.m_fov;
    m_resolutionX = m_cam.m_renderWidth;
    m_resolutionY = m_cam.m_renderHeight;
}

PathTracer::~PathTracer() {
    delete[] m_renderData;
}

void PathTracer::MainLoop() {
    while(m_window.BeginWindow()) {

        int w, h;
        m_cam.RenderTo(m_renderData, w, h);

        m_mainCanvas.UpdateTex(m_renderData, w, h);
        m_mainCanvas.Render();

        renderCameraProps();

        m_window.EndWindow();
    }
}

void PathTracer::renderCameraProps() {

    ImGui::Begin("camera ");

    ImGui::SliderFloat("fov", &m_camFov, 0.0f, 180.0f);
    m_cam.m_fov = (double)m_camFov;

    ImGui::SliderInt("resolution x", &m_resolutionX, 1, m_resolutionMaxX);
    m_cam.m_renderWidth = m_resolutionX;

    ImGui::SliderInt("resolution y", &m_resolutionY, 1, m_resolutionMaxY);
    m_cam.m_renderHeight = m_resolutionY;

    ImGui::End();
}

