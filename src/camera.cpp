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
#include "sphere.hpp"

Camera::Camera(const Vec3 &pos, double fov, int renderHeight, int renderWidth)
        : m_pos(pos), m_fov(fov), m_renderHeight(renderHeight), m_renderWidth(renderWidth),
          m_rayDepth(10) {

    m_aspectRatio = (double)m_renderWidth / m_renderHeight;

    updateConfig();
}

Ray Camera::getRay(double x, double y) {
    Vec3 origin = m_pos;

    Vec3 viewportPoint = m_vp_leftBottom
                         + ((x + 0.5f) / m_renderWidth) * m_viewportRight
                         + ((y + 0.5f) / m_renderHeight) * m_viewportUp;

    Vec3 direction = (viewportPoint - origin).normalized();

    return {origin, direction};
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

void Camera::RenderTo(Scene *scene, unsigned char *buf, int &w, int &h) {
    updateConfig();

    w = m_renderWidth;
    h = m_renderHeight;

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int idx = y * w + x;
            Ray ray = getRay(x, y);
            Color color = RayColor(ray, scene, m_rayDepth);

            buf[idx*4 + 0] = color.r8();
            buf[idx*4 + 1] = color.g8();
            buf[idx*4 + 2] = color.b8();
            buf[idx*4 + 3] = color.a8();

        }
    }
}

Color Camera::RayColor(const Ray &ray, Scene *scene, int depth) {
    HitPayload payload;

    // if exceeded the ray bounce limit, then we assume that no more lights.
    if(depth <= 0) {
        return {0.f, 0.f, 0.f};
    }

    // if hit object, then scatter and rayCast again
    if(scene->RayCast(ray, payload, 0.001f, infinity)) {
        Ray scattered;
        Color attenuation;
        if(payload.hitObject->mat->Scatter(ray, scattered, payload, attenuation)) {
            return attenuation * RayColor(scattered, scene, depth-1);
        }
    }

    // if not hit, then return background color
    return getSkyBoxColor(ray);
}

Color Camera::getSkyBoxColor(const Ray &ray) {
    return Color();
}


