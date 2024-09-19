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

bool Sphere::CheckHit(Ray ray) {
    Vec3 oc = m_center - ray.origin();
    auto a = Vec3::Dot(ray.direction(), ray.direction());
    auto b = -2.0f * Vec3::Dot(ray.direction(), oc);
    auto c = Vec3::Dot(oc, oc) - m_radius * m_radius;
    double t0, t1;
    bool existSolution = MathTool::SolveQuadratic(a, b, c, t0, t1);
    if(existSolution && t1 > 0.f) {
        return true;
    }
    else {
        return false;
    }
}

Color Sphere::Raycast(Ray ray) {
    Vec3 oc = m_center - ray.origin();
    auto a = Vec3::Dot(ray.direction(), ray.direction());
    auto b = -2.0f * Vec3::Dot(ray.direction(), oc);
    auto c = Vec3::Dot(oc, oc) - m_radius * m_radius;
    double t0, t1;
    bool existSolution = MathTool::SolveQuadratic(a, b, c, t0, t1);
    if(existSolution) {
        if(t0 >= 0.f){
            Vec3 hitPoint = ray.GetPoint(t0);
            Vec3 norm = (hitPoint - m_center).normalized();
            return {norm.x(), norm.y(), norm.z(), 1.0f};
        }
        else if(t1 >= 0.f) {
            Vec3 hitPoint = ray.GetPoint(t0);
            Vec3 norm = (hitPoint - m_center).normalized();
            return {norm.x(), norm.y(), norm.z(), 1.0f};
        }
    }
    else {
        return {0.f, 0.f, 0.f, 1.f};
    }
}
