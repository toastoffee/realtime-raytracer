/**
  ******************************************************************************
  * @file           : mesh_object.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/30
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_MESH_OBJECT_HPP
#define REALTIME_RAYTRACER_MESH_OBJECT_HPP

#include "mesh.hpp"
#include "object.hpp"

#include <vector>

#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>


class MeshObject : public Object {
private:
    std::vector<Mesh*> m_meshes;    // all meshes

    // load model with assimp and save it to m_meshes
    void loadMeshes(const std::string &path);

    // process node recursively, repeat if there exists children nodes
    void processNode(aiNode *node, const aiScene *scene);

    // transform aiMesh to mesh
    Mesh* processMesh(aiMesh *mesh, const aiScene *scene);

public:
    bool CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) override;
};


#endif //REALTIME_RAYTRACER_MESH_OBJECT_HPP
