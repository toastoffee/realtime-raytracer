/**
  ******************************************************************************
  * @file           : scene.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/19
  ******************************************************************************
  */


#include "scene.hpp"

const std::vector<std::unique_ptr<Object>> &Scene::GetObjects() const {
    return m_objects;
}

void Scene::AddObject(std::unique_ptr<Object> object) {
    m_objects.push_back(std::move(object));
}

bool Scene::RayCast(const Ray &ray, HitPayload &payload, double minRange, double maxRange) {
    HitPayload currentPayload;
    bool hitAnything = false;
    double closestRange = maxRange;

    for (auto& object : m_objects) {
        if(object->CheckHit(ray, currentPayload, minRange, closestRange)) {
            hitAnything = true;
            closestRange = currentPayload.t;
            payload = currentPayload;
        }
    }

    return hitAnything;
}
