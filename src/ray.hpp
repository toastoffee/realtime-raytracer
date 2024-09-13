/**
  ******************************************************************************
  * @file           : ray.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/13
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_RAY_HPP
#define REALTIME_RAYTRACER_RAY_HPP

#include "vec3.hpp"

class Ray {
private:
    Vec3 m_origin;
    Vec3 m_dir;

public:
    Ray(const Vec3 &origin, const Vec3 &dir);

    Vec3 origin() const;
    Vec3 direction() const;

    Vec3 GetPoint(double t) const;
};


#endif //REALTIME_RAYTRACER_RAY_HPP
