/**
  ******************************************************************************
  * @file           : random.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/27
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_RANDOM_HPP
#define REALTIME_RAYTRACER_RANDOM_HPP

#include "vec3.hpp"


class Random {
private:
    static double randZeroToOne();

public:
    static double Range(double min, double max);

    static Vec3 RandVecOnUnitSphere();
};


#endif //REALTIME_RAYTRACER_RANDOM_HPP
