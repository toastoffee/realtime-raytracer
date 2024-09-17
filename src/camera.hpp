/**
  ******************************************************************************
  * @file           : camera.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/15
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_CAMERA_HPP
#define REALTIME_RAYTRACER_CAMERA_HPP

#include "vec3.hpp"
#include "ray.hpp"
#include "color.hpp"

class Camera {
private:
    Vec3 m_pos;
    Vec3 m_right, m_up, m_forward;
    int m_renderWidth, m_renderHeight;

    double m_aspectRatio;   // width / height
    double m_fov;   // vertical view range

    Vec3 m_vp_leftBottom;
    Vec3 m_viewportUp, m_viewportRight;

private:
    Ray getRay(double x, double y);

public:
    Camera(const Vec3& pos, double aspectRatio, double fov, int renderHeight);     // create a front-warded camera

    Color *Render(int &w, int &h);
};


#endif //REALTIME_RAYTRACER_CAMERA_HPP
