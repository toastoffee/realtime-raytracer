/**
  ******************************************************************************
  * @file           : canvas.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/14
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_CANVAS_HPP
#define REALTIME_RAYTRACER_CANVAS_HPP

#include "color.hpp"

class Canvas {
private:
    int m_width, m_height;
    unsigned int m_tex;

public:
    Canvas();
    ~Canvas();

    void UpdateTex(unsigned char* pixels, int w, int h);

    void Render() const;
};


#endif //REALTIME_RAYTRACER_CANVAS_HPP
