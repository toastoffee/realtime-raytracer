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
    const std::vector<std::unique_ptr<Object>>& GetObjects() const { return m_objects; }

    void AddObject(std::unique_ptr<Object> object) { m_objects.push_back(std::move(object)); }
};


#endif //REALTIME_RAYTRACER_SCENE_HPP
