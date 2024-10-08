/**
  ******************************************************************************
  * @file           : color.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/14
  ******************************************************************************
  */


#include <cmath>

#include "color.hpp"

Color::Color() :
m_r(0.0f), m_g(0.0f), m_b(0.0f), m_a(1.0f) {}

Color::Color(double r, double g, double b) :
m_r(r), m_g(g), m_b(b), m_a(1.0f) {}

Color::Color(double r, double g, double b, double a) :
m_r(r), m_g(g), m_b(b), m_a(a) {}


Color::Color(unsigned char r, unsigned char g, unsigned char b) {
    SetR(static_cast<double>(r) / 255.0f);
    SetG(static_cast<double>(g) / 255.0f);
    SetB(static_cast<double>(b) / 255.0f);
    m_a = 1.0f;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    SetR(static_cast<double>(r) / 255.0f);
    SetG(static_cast<double>(g) / 255.0f);
    SetB(static_cast<double>(b) / 255.0f);
    SetA(static_cast<double>(a) / 255.0f);
}

double Color::clamp(double x, double min, double max) {
    if(x < min){
        return min;
    } else if(x > max) {
        return max;
    } else {
        return x;
    }
}

double Color::linearToGamma(double x, double gamma) {
    // gamma = 2.0
    return pow(x, 1.0 / gamma);
}

unsigned char Color::convertTo8(double x) {
    return static_cast<unsigned char>(256.0f * clamp(x, 0.0, 0.9999));
}

double Color::r() const {
    return m_r;
}

double Color::g() const {
    return m_g;
}

double Color::b() const {
    return m_b;
}

double Color::a() const {
    return m_a;
}

unsigned char Color::r8() const {
    return convertTo8(m_r);
}

unsigned char Color::g8() const {
    return convertTo8(m_g);
}

unsigned char Color::b8() const {
    return convertTo8(m_b);
}

unsigned char Color::a8() const {
    return convertTo8(m_a);
}

void Color::SetR(double r) {
    m_r = clamp(r, 0.0f, 1.0f);
}

void Color::SetG(double g) {
    m_g = clamp(g, 0.0f, 1.0f);
}

void Color::SetB(double b) {
    m_b = clamp(b, 0.0f, 1.0f);
}

void Color::SetA(double a) {
    m_a = clamp(a, 0.0f, 1.0f);
}

Color Color::gamma(double g) const {
    return {linearToGamma(m_r, g), linearToGamma(m_g, g), linearToGamma(m_b, g), m_a};
}

Color &Color::operator*=(double t) {
    SetR(m_r * t);
    SetG(m_g * t);
    SetB(m_b * t);

    return *this;
}

Color &Color::operator*=(const Color &v) {
    SetR(m_r * v.r());
    SetG(m_g * v.g());
    SetB(m_b * v.b());

    return *this;
}

Color operator*(const Color &lhs, const Color &rhs) {
    return {lhs.r() * rhs.r(),
            lhs.g() * rhs.g(),
            lhs.b() * rhs.b()};
}

Color operator*(double t, const Color &v) {
    return {v.r() * t, v.g() * t , v.b() * t};
}

Color operator*(const Color &v, double t) {
    return t * v;
}
