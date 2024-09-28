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
    static double linearToGamma(double x, double gamma);
    static unsigned char convertTo8(double x);

public:
    Color();
    Color(double r, double g, double b);
    Color(double r, double g, double b, double a);
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

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

    Color gamma(double g) const;

    Color& operator*=(double t);
    Color& operator*=(const Color &v);
};

Color operator*(const Color &lhs, const Color &rhs);
Color operator*(double t, const Color &v);
Color operator*(const Color &v, double t);

#endif //REALTIME_RAYTRACER_COLOR_HPP
