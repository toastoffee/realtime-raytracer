/**
  ******************************************************************************
  * @file           : vec3.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/12
  ******************************************************************************
  */



#include "vec3.hpp"


Vec3::Vec3() : m_e{0, 0, 0} { }

Vec3::Vec3(double x, double y, double z)
 : m_e{x, y, z} { }

Vec3 Vec3::zero() { return {0, 0, 0}; }

Vec3 Vec3::one() { return {1, 1, 1}; }

Vec3 Vec3::up() { return {0, 1, 0}; }

Vec3 Vec3::down() { return {0, -1, 0}; }

Vec3 Vec3::left() { return {-1, 0, 0}; }

Vec3 Vec3::right() { return {1, 0, 0}; }

Vec3 Vec3::forward() { return {0, 0, 1}; }

Vec3 Vec3::back() { return {0, 0, -1}; }

double Vec3::x() const { return m_e[0]; }

double Vec3::y() const { return m_e[1]; }

double Vec3::z() const { return m_e[2]; }

Vec3 Vec3::operator-() const { return {-m_e[0], -m_e[1], -m_e[2]}; }

double Vec3::operator[](int i) const { return m_e[i]; }

double &Vec3::operator[](int i) { return m_e[i]; }

Vec3 &Vec3::operator+=(const Vec3 &v) {
    m_e[0] += v.x();
    m_e[1] += v.y();
    m_e[2] += v.z();
    return *this;
}

Vec3 &Vec3::operator-=(const Vec3 &v) {
    m_e[0] -= v.x();
    m_e[1] -= v.y();
    m_e[2] -= v.z();
    return *this;
}

Vec3 &Vec3::operator/=(const double t) {
    m_e[0] /= t;
    m_e[1] /= t;
    m_e[2] /= t;
    return *this;
}

Vec3 &Vec3::operator*=(const double t) {
    m_e[0] *= t;
    m_e[1] *= t;
    m_e[2] *= t;
    return *this;
}

double Vec3::magnitude() const {
    return 0;
}

double Vec3::sqrMagnitude() const {
    return 0;
}

Vec3 Vec3::normalized() const {
    return Vec3();
}

void Vec3::Normalize() {

}

double Vec3::Dot(const Vec3 &lhs, const Vec3 &rhs) {
    return 0;
}

double Vec3::Distance(const Vec3 &lhs, const Vec3 &rhs) {
    return 0;
}

Vec3 Vec3::Cross(const Vec3 &lhs, const Vec3 &rhs) {
    return Vec3();
}

std::ostream &operator<<(std::ostream &o, const Vec3 &v) {
    return <#initializer#>;
}

Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z()};
}

Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z()};
}

Vec3 operator*(double t, const Vec3 &v) {
    return {t * v.x(), t * v.y(), t * v.z()};
}

Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

Vec3 operator/(const Vec3 &v, double t) {
    return {v.x() / t, v.y() / t, v.z() / t};
}
