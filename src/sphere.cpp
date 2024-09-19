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
#include "math_tool.hpp"

Sphere::Sphere(const Vec3 &mCenter, double mRadius) : m_center(mCenter), m_radius(mRadius) {}

bool Sphere::CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) {

    Vec3 oc = m_center - ray.origin();
    auto a = Vec3::Dot(ray.direction(), ray.direction());
    auto b = -2.0f * Vec3::Dot(ray.direction(), oc);
    auto c = Vec3::Dot(oc, oc) - m_radius * m_radius;

    double t0, t1;
    bool existSolution = MathTool::SolveQuadratic(a, b, c, t0, t1);
    if(!existSolution) {
        return false;
    }

    double t;
    if(MathTool::isInInterval(t0, minRange, maxRange)) {
        t = t0;
    } else if(MathTool::isInInterval(t1, minRange, maxRange)) {
        t = t1;
    } else {
        return false;
    }

    Vec3 outwardNormal = (payload.p - m_center).normalized();
    payload.p = ray.GetPoint(t);
    payload.SetNormalAndHitFront(ray, outwardNormal);
    payload.hitObject = this;

    return true;
}
