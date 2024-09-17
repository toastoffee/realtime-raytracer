/**
  ******************************************************************************
  * @file           : camera.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/15
  ******************************************************************************
  */



#include "camera.hpp"
#include "math_tool.hpp"


Camera::Camera(const Vec3& pos, double fov, double aspectRatio, int renderHeight)
 : m_pos(pos), m_aspectRatio(aspectRatio), m_fov(fov) {

    m_right = Vec3::right();
    m_up = Vec3::up();
    m_forward = Vec3::forward();

    m_renderHeight = renderHeight;
    m_renderWidth = static_cast<int>(m_renderHeight * aspectRatio);

    double viewportDist = 1.0f;
    double viewportHeight = 2.f * MathTool::tan(MathTool::Deg2Rad(fov/2)) * viewportDist;
    double viewportWidth = viewportHeight * aspectRatio;

    m_viewportUp = m_up * viewportHeight;
    m_viewportRight = m_right * viewportWidth;

    m_vp_leftBottom = m_pos
                      + m_forward * viewportDist
                      - m_viewportUp / 2
                      - m_viewportRight / 2;
}

Ray Camera::getRay(double x, double y) {
    Vec3 origin = m_pos;

    Vec3 viewportPoint = m_vp_leftBottom
                         + ((x + 0.5f) / m_renderWidth) * m_viewportRight
                         + ((y + 0.5f) / m_renderHeight) * m_viewportUp;

    Vec3 direction = (viewportPoint - origin).normalized();

    return {origin, direction};
}

Color *Camera::Render(int &w, int &h) {
    w = m_renderWidth;
    h = m_renderHeight;

    auto *data = new Color[w * h];
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            int idx = i + j * w;
            Ray ray = getRay(i, j);
            Vec3 dir = ray.direction();
            data[idx] = Color(dir.x(), dir.y(), dir.z(), 1.0f);
        }
    }
    return data;
}

Camera::Camera(const Vec3 &pos, double fov, int renderHeight, int renderWidth)
 : m_pos(pos), m_fov(fov), m_renderHeight(renderHeight), m_renderWidth(renderWidth) {
    m_aspectRatio = (double)m_renderWidth / m_renderHeight;

    updateConfig();
}

void Camera::updateConfig() {
    m_right = Vec3::right();
    m_up = Vec3::up();
    m_forward = Vec3::forward();

    double viewportDist = 1.0f;
    double viewportHeight = 2.f * MathTool::tan(MathTool::Deg2Rad(m_fov/2)) * viewportDist;
    double viewportWidth = viewportHeight * m_aspectRatio;

    m_viewportUp = m_up * viewportHeight;
    m_viewportRight = m_right * viewportWidth;

    m_vp_leftBottom = m_pos
                      + m_forward * viewportDist
                      - m_viewportUp / 2
                      - m_viewportRight / 2;
}

void Camera::RenderTo(unsigned char *buf, int &w, int &h) {
    updateConfig();

    w = m_renderWidth;
    h = m_renderHeight;

    auto *data = new Color[w * h];
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            int idx = i + j * w;
            Ray ray = getRay(i, j);
            Vec3 dir = ray.direction();
            data[idx] = Color(dir.x(), dir.y(), dir.z(), 1.0f);
        }
    }
}
