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
    /*! user set params */
    Vec3 m_pos;
    double m_fov;   // vertical view range
    int m_renderWidth, m_renderHeight;
    double m_aspectRatio;   // width / height

    /*! calc params */
    Vec3 m_right, m_up, m_forward;
    Vec3 m_vp_leftBottom;
    Vec3 m_viewportUp, m_viewportRight;

private:
    void updateConfig();
    Ray getRay(double x, double y);

public:
    Camera(const Vec3& pos, double fov, int renderHeight, int renderWidth);

    Color *Render(int &w, int &h);
};


#endif //REALTIME_RAYTRACER_CAMERA_HPP
