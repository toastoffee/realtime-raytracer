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

class Camera {
private:
    Vec3 m_pos;
    Vec3 m_right, m_front;
    double m_aspectRatio;   // width / height
    double m_fov;   // vertical view range

    Vec3 m_vp_leftBottom;

private:
    Ray getRay(double x, double y);

public:
    Camera(const Vec3& pos, double aspectRatio, double fov);     // create a front-warded camera
};


#endif //REALTIME_RAYTRACER_CAMERA_HPP
