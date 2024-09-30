/**
  ******************************************************************************
  * @file           : mesh_object.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/30
  ******************************************************************************
  */



#include "mesh_object.hpp"

void MeshObject::loadMeshes(const std::string &path) {

}

void MeshObject::processNode(aiNode *node, const aiScene *scene) {

}

Mesh *MeshObject::processMesh(aiMesh *mesh, const aiScene *scene) {
    return nullptr;
}

bool MeshObject::CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) {
    return false;
}
