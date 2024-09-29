/**
  ******************************************************************************
  * @file           : Triangle.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/29
  ******************************************************************************
  */



#include "Triangle.hpp"
#include "math_tool.hpp"

Triangle::Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c) :
 m_a(a), m_b(b), m_c(c) { }

bool Triangle::CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) {
    double tNear;
    bool isIntersected = MathTool::CheckTriangleIntersect(m_a, m_b, m_c, ray, tNear);

    // no intersection or beyond range
    if(!isIntersected || !MathTool::isInInterval(tNear, minRange, maxRange)) {
        return false;
    }


    payload.t = tNear;
    payload.p = ray.GetPoint(tNear);
    Vec3 outwardNormal = Vec3::Cross(m_b - m_a, m_c - m_a).normalized();
    payload.SetNormalAndHitFront(ray, outwardNormal);
    payload.hitObject = this;

    return true;
}
