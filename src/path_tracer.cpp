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
    m_cam(Vec3::zero(), 90.f, 1600, 900),
    m_window(1280, 720),
    m_resolutionMaxX(2048), m_resolutionMaxY(2048) {

    m_renderData = new unsigned char[m_resolutionMaxX * m_resolutionMaxY * 4];
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
        m_window.EndWindow();
    }
}

