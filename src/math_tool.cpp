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
