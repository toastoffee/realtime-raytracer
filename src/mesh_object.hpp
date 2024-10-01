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
#include <string>

#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include "triangle.hpp"

class MeshObject : public Object {
private:
    Vec3 m_pos;     // object pos
    std::vector<Mesh*> m_meshes;    // all meshes
    std::vector<Triangle> m_triangles;

private:
    // load model with assimp and save it to m_meshes
    void loadMeshes(const std::string &path);

    // process node recursively, repeat if there exists children nodes
    void processNode(aiNode *node, const aiScene *scene);

    // transform aiMesh to mesh
    static Mesh* convertMesh(aiMesh *mesh, const aiScene *scene);

public:
    explicit MeshObject(const std::string &path, const Vec3 &pos, const std::shared_ptr<Material> &material);

    bool CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) override;
};


#endif //REALTIME_RAYTRACER_MESH_OBJECT_HPP
