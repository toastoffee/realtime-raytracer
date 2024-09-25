/**
  ******************************************************************************
  * @file           : texture.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/25
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_TEXTURE2D_HPP
#define REALTIME_RAYTRACER_TEXTURE2D_HPP

#include <string>
#include "color.hpp"

class Texture2D {
private:
    int m_w, m_h;
    unsigned char *m_data;

private:
    Color getColor(int x, int y) const;

public:
    Texture2D(unsigned char *data, int w, int h);

    Color Sample(float x, float y) const;
};


#endif //REALTIME_RAYTRACER_TEXTURE2D_HPP
