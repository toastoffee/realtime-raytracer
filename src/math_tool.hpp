/**
  ******************************************************************************
  * @file           : math_tool.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/15
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_MATH_TOOL_HPP
#define REALTIME_RAYTRACER_MATH_TOOL_HPP

#include <limits>

const double PI = 3.1415926535897932385;
const double infinity =  std::numeric_limits<double>::infinity();

class MathTool {
public:
    static double Deg2Rad(double degrees);
    static double Rad2Deg(double radians);

    static double tan(double radians);
    static double sin(double radians);
    static double cos(double radians);

    static double sqrt(double v);

    static void Swap(double &l, double &r);

    static double Clamp(double x, double min, double max);
    static int Clamp(int x, int min, int max);

    static bool isInInterval(double v, double min, double max);

    static bool SolveQuadratic(double a, double b, double c, double &x0, double &x1);
};


#endif //REALTIME_RAYTRACER_MATH_TOOL_HPP
