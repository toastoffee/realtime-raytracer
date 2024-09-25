/**
  ******************************************************************************
  * @file           : material.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/24
  ******************************************************************************
  */



#include "material.hpp"
#include "object.hpp"

Metal::Metal(const Color &albedo, double fuzz) :
 m_albedo(albedo), m_fuzz(fuzz < 1.0f ? fuzz : 1.0f) { }


bool Metal::Scatter(const Ray &rayIn, Ray &rayScattered, const HitPayload &payload, Color &attenuation) const {
    Vec3 reflected = Vec3::Reflect(rayIn.direction().normalized(), payload.normal);
    rayScattered = Ray(payload.p, reflected);
    attenuation = m_albedo;
    return Vec3::Dot(rayScattered.direction(), payload.normal) > 0.0f;
}
