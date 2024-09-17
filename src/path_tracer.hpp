/**
  ******************************************************************************
  * @file           : path_tracer.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/17
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_PATH_TRACER_HPP
#define REALTIME_RAYTRACER_PATH_TRACER_HPP

#include "render_window.hpp"
#include "canvas.hpp"
#include "camera.hpp"

class PathTracer {
private:
    Camera m_cam;
    Canvas m_mainCanvas;
    RenderWindow m_window;

    int m_resolutionMaxX, m_resolutionMaxY;
    unsigned char *m_renderData;

public:
    PathTracer();

    void MainLoop();
};


#endif //REALTIME_RAYTRACER_PATH_TRACER_HPP
