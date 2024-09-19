/**
  ******************************************************************************
  * @file           : sphere.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/18
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_SPHERE_HPP
#define REALTIME_RAYTRACER_SPHERE_HPP

#include "vec3.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "object.hpp"

class Sphere : public Object {
private:
    Vec3 m_center;
    double m_radius;

public:
    Sphere(const Vec3 &mCenter, double mRadius);

    bool CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) override;
};


#endif //REALTIME_RAYTRACER_SPHERE_HPP
