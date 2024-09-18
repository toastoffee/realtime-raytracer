/**
  ******************************************************************************
  * @file           : sphere.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/18
  ******************************************************************************
  */



#include "sphere.hpp"

Sphere::Sphere(const Vec3 &mCenter, double mRadius) : m_center(mCenter), m_radius(mRadius) {}

bool Sphere::Raycast(Ray ray) {
    return false;
}
