/**
  ******************************************************************************
  * @file           : mesh.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/29
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_MESH_HPP
#define REALTIME_RAYTRACER_MESH_HPP

#include "ray.hpp"
#include "color.hpp"
#include "object.hpp"

#include <string>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>


class Mesh : public Object {
private:
    void loadMesh(const std::string &path);

    void processNode(aiNode *node, const aiScene *scene);

    void processMesh(aiMesh *mesh, const aiScene *scene);

public:

    bool CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) override;
};



#endif //REALTIME_RAYTRACER_MESH_HPP
