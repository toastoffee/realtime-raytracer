/**
  ******************************************************************************
  * @file           : random.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/27
  ******************************************************************************
  */


#include <cstdlib>

#include "random.hpp"
#include "math_tool.hpp"

double Random::randZeroToOne() {
    return std::rand() / (RAND_MAX + 1.0);
}

double Random::Range(double min, double max) {
    return min + randZeroToOne() * (max - min);
}

Vec3 Random::RandVecOnUnitSphere() {
    double radius = 1.0f;
    double theta = Range(0.f, 180.f) * MathTool::deg2Rad;
    double phi = Range(0.f, 360.f) * MathTool::deg2Rad;

    double x = radius * MathTool::sin(theta) * MathTool::cos(phi);
    double y = radius * MathTool::sin(theta) * MathTool::sin(phi);
    double z = radius * MathTool::cos(theta);

    return {x, y, z};
}


