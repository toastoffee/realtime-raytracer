/**
  ******************************************************************************
  * @file           : object.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/19
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_OBJECT_HPP
#define REALTIME_RAYTRACER_OBJECT_HPP

#include <vector>

#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"

class Object;

class HitPayload {
public:
    Vec3 p;
    double t;
    Vec3 normal;
    bool hitFront;
    Object *hitObject;

    void SetNormalAndHitFront(const Ray& ray, const Vec3& outwardNormal);
};

class Object {
public:
    std::shared_ptr<Material> mat;

public:
    virtual ~Object() = default;

    virtual bool CheckHit(const Ray& ray, HitPayload &payload, double minRange, double maxRange) = 0;
};


#endif //REALTIME_RAYTRACER_OBJECT_HPP
