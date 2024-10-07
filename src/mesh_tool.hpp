/**
  ******************************************************************************
  * @file           : mesh_object.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/30
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_MESH_TOOL_HPP
#define REALTIME_RAYTRACER_MESH_TOOL_HPP

#include "mesh.hpp"
#include "object.hpp"

#include <vector>
#include <string>

#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include "triangle.hpp"
#include "scene.hpp"

class MeshTool {
private:

    // process node recursively, repeat if there exists children nodes
    static void processNode(aiNode *node, const aiScene *aScene, const Vec3 &pos, const std::shared_ptr<Material> &mat,  std::shared_ptr<Scene> &scene);

    // transform aiMesh to mesh
    static Mesh* convertMesh(aiMesh *mesh, const aiScene *scene);

public:

    static void LoadTrianglesToScene(const std::string &path, const Vec3 &pos, const std::shared_ptr<Material> &mat,  std::shared_ptr<Scene> &scene);

};


#endif //REALTIME_RAYTRACER_MESH_TOOL_HPP
