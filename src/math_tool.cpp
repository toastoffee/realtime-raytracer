/**
  ******************************************************************************
  * @file           : math_tool.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/15
  ******************************************************************************
  */


#include "math_tool.hpp"

#include <cmath>

double MathTool::deg2Rad = PI / 180.0f;
double MathTool::rad2Deg = 180.0f / PI;

double MathTool::Deg2Rad(double degrees) {
    return degrees * PI / 180.0f;
}

double MathTool::Rad2Deg(double radians) {
    return radians * 180.0f / PI;
}

double MathTool::tan(double radians) {
    return std::tan(radians);
}

double MathTool::sin(double radians) {
    return std::sin(radians);
}

double MathTool::cos(double radians) {
    return std::cos(radians);
}

double MathTool::sqrt(double v) {
    return std::sqrt(v);
}

void MathTool::Swap(double &l, double &r) {
    double temp = l;
    l = r;
    r = temp;
}

bool MathTool::isInInterval(double v, double min, double max) {
    return v >= min && v <= max;
}

bool MathTool::SolveQuadratic(double a, double b, double c, double &x0, double &x1) {
    double discriminant = b*b - 4*a*c;

    if(discriminant < 0) {
        return false;
    }
    else if(discriminant == 0) {
        x0 = x1 = -0.5f * b / a;
    }
    else {
        double sqrtDiscriminant = sqrt(discriminant);
        x0 = -0.5f * ( b + sqrtDiscriminant ) / a;
        x1 = -0.5f * ( b - sqrtDiscriminant ) / a;

        if(x0 > x1) {
            // swap
            Swap(x0, x1);
        }
    }
    return true;
}

double MathTool::Clamp(double x, double min, double max) {
    if(x < min){
        return min;
    } else if(x > max) {
        return max;
    } else {
        return x;
    }
}

int MathTool::Clamp(int x, int min, int max) {
    if(x < min){
        return min;
    } else if(x > max) {
        return max;
    } else {
        return x;
    }
}

bool MathTool::CheckTriangleIntersect(const Vec3 &v0, const Vec3 &v1, const Vec3 &v2, const Ray &ray, double &tNear) {

    // triangle is counter-clockwise aligned
    auto ab = v1 - v0;  // AB
    auto ac = v2 - v0;  // AC
    auto n = Vec3::Cross(ab, ac);

    // check if denominator is not 0
    auto denominator = Vec3::Dot(ray.direction(), n);
    if(denominator == 0.f) {
        return false;
    }

    // check if t greater than 0
    auto t = Vec3::Dot(v0 - ray.origin(), n) / denominator;
    if(t < 0.f) {
        return false;
    }

    auto p = ray.GetPoint(t);

    auto bc = v2 - v1;
    auto ca = v0 - v2;
    auto signDir = Vec3::Cross(ab, ac);
    bool sign_ab = Vec3::Dot(signDir, Vec3::Cross(ab, p - v0)) > 0;
    bool sign_bc = Vec3::Dot(signDir, Vec3::Cross(bc, p - v1)) > 0;
    bool sign_ca = Vec3::Dot(signDir, Vec3::Cross(ca, p - v2)) > 0;

    return sign_ab && sign_bc && sign_ca;
}




