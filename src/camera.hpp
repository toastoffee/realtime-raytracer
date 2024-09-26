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
#include "scene.hpp"
#include "skybox.hpp"

class Camera {
public:
    /*! user set params */
    Vec3 m_pos;
    double m_fov;   // vertical view range
    int m_renderWidth, m_renderHeight;
    int m_rayDepth;

private:
    /*! calc params */
    double m_aspectRatio;   // width / height
    Vec3 m_right, m_up, m_forward;
    Vec3 m_vp_leftBottom;
    Vec3 m_viewportDown, m_viewportRight;
    SkyBox m_skyBox;
    int m_lastY, m_lastX;
    int m_samples;

private:
    void updateConfig();

    Ray getRay(double x, double y);

    Color getSkyBoxColor(const Ray& ray);

public:
    Camera(const Vec3& pos, double fov, int renderHeight, int renderWidth, const std::string &cubeMapDir);

    void RenderTo(Scene *scene, unsigned char *buf, int &w, int &h);

    Color RayColor(const Ray &ray, Scene *scene, int depth);
};


#endif //REALTIME_RAYTRACER_CAMERA_HPP
