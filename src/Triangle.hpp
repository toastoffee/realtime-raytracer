/**
  ******************************************************************************
  * @file           : Triangle.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/29
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_TRIANGLE_HPP
#define REALTIME_RAYTRACER_TRIANGLE_HPP

#include "vec3.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "object.hpp"

class Triangle : public Object {
private:
    Vec3 m_a;
    Vec3 m_b;
    Vec3 m_c;

public:
    Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c);

    bool CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) override;
};


#endif //REALTIME_RAYTRACER_TRIANGLE_HPP
