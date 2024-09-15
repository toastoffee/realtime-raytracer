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



Camera::Camera(const Vec3 &pos, double aspectRatio, double fov)
 : m_pos(pos), m_aspectRatio(aspectRatio), m_fov(fov) {
    m_right = Vec3::right();
    m_front = Vec3::forward();


}