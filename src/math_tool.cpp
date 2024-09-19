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




