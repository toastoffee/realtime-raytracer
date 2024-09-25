/**
  ******************************************************************************
  * @file           : material.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/24
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_MATERIAL_HPP
#define REALTIME_RAYTRACER_MATERIAL_HPP

#include "ray.hpp"
#include "color.hpp"

class HitPayload;

class Material {
public:
    virtual bool Scatter(const Ray& rayIn, Ray& rayScattered, const HitPayload& payload, Color& attenuation) const = 0;
};


#endif //REALTIME_RAYTRACER_MATERIAL_HPP
