/**
  ******************************************************************************
  * @file           : ray.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/13
  ******************************************************************************
  */



#include "ray.hpp"

Ray::Ray(const Vec3 &origin, const Vec3 &dir)
: m_origin(origin), m_dir(dir) { }

Ray::Ray()
: m_origin(), m_dir() { }

Vec3 Ray::origin() const {
    return m_origin;
}

Vec3 Ray::direction() const {
    return m_dir;
}

Vec3 Ray::GetPoint(double t) const {
    return m_origin + t * m_dir;
}

