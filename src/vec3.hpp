/**
  ******************************************************************************
  * @file           : vec3.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/12
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_VEC3_HPP
#define REALTIME_RAYTRACER_VEC3_HPP

#include <iostream>

class Vec3 {
private:
    double m_e[3];

public:

    Vec3();
    Vec3(double x, double y, double z);

    /** @brief shorthand for writing Vector3(0, 0, 0) */
    static Vec3 zero();
    /** @brief shorthand for writing Vector3(1, 1, 1) */
    static Vec3 one();
    /** @brief shorthand for writing Vector3(0, 1, 0) */
    static Vec3 up();
    /** @brief shorthand for writing Vector3(0, -1, 0) */
    static Vec3 down();
    /** @brief shorthand for writing Vector3(-1, 0, 0) */
    static Vec3 left();
    /** @brief shorthand for writing Vector3(1, 0, 0) */
    static Vec3 right();
    /** @brief shorthand for writing Vector3(0, 0, 1) */
    static Vec3 forward();
    /** @brief shorthand for writing Vector3(0, 0, -1) */
    static Vec3 back();

    double x() const;
    double y() const;
    double z() const;

    Vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    Vec3& operator+=(const Vec3 &v);
    Vec3& operator-=(const Vec3 &v);
    Vec3& operator/=(double t);
    Vec3& operator*=(double t);

    double magnitude() const;
    double sqrMagnitude() const;

    Vec3 normalized() const;
    void Normalize();

    static double Dot(const Vec3 &lhs, const Vec3 &rhs);
    static double Distance(const Vec3 &lhs, const Vec3 &rhs);
    static Vec3 Cross(const Vec3 &lhs, const Vec3 &rhs);
    static double Angle(const Vec3 &lhs, const Vec3 &rhs);

    static Vec3 Reflect(const Vec3 &inDir, const Vec3 &inNorm);
};

std::ostream& operator<<(std::ostream &o, const Vec3 &v);

Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs);
Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs);
Vec3 operator*(double t, const Vec3 &v);
Vec3 operator*(const Vec3 &v, double t);
Vec3 operator/(const Vec3 &v, double t);


#endif //REALTIME_RAYTRACER_VEC3_HPP
