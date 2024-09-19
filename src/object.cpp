/**
  ******************************************************************************
  * @file           : object.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/19
  ******************************************************************************
  */



#include "object.hpp"

void HitPayload::SetNormalAndHitFront(const Ray &ray, const Vec3 &outwardNormal) {
    // set correct normal direction
    hitFront = Vec3::Dot(ray.direction(), outwardNormal) < 0;
    normal = hitFront ? outwardNormal.normalized() : - outwardNormal.normalized();
}
