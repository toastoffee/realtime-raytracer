/**
  ******************************************************************************
  * @file           : scene.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/19
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_SCENE_HPP
#define REALTIME_RAYTRACER_SCENE_HPP

#include "object.hpp"

class Scene {
private:
    std::vector<std::unique_ptr<Object> > m_objects;

public:
    const std::vector<std::unique_ptr<Object>>& GetObjects() const;

    void AddObject(std::unique_ptr<Object> object);

    bool RayCast(const Ray& ray, HitPayload &payload, double minRange, double maxRange);
};


#endif //REALTIME_RAYTRACER_SCENE_HPP
