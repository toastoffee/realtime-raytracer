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
    Color *m_pixels;
    unsigned char *m_texData;
    int m_width, m_height;
    unsigned int m_tex;

public:
    Canvas(int width, int height);
    ~Canvas();

    void WriteInPixel(const Color &color, int x, int y);
    void UpdateTex();

    void Render() const;
};


#endif //REALTIME_RAYTRACER_CANVAS_HPP
