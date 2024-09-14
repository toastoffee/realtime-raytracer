/**
  ******************************************************************************
  * @file           : color.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/14
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_COLOR_HPP
#define REALTIME_RAYTRACER_COLOR_HPP


class Color {
private:
    double m_r, m_g, m_b, m_a;

    static double clamp(double x, double min, double max);
    static double linearToGamma(double x);
    static unsigned char convertTo8(double x);

public:
    Color();
    Color(double r, double g, double b, double a);

    double r() const;
    double g() const;
    double b() const;
    double a() const;

    unsigned char r8() const;
    unsigned char g8() const;
    unsigned char b8() const;
    unsigned char a8() const;

    void SetR(double r);
    void SetG(double g);
    void SetB(double b);
    void SetA(double a);

    Color gamma() const;
};


#endif //REALTIME_RAYTRACER_COLOR_HPP
