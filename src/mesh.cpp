/**
  ******************************************************************************
  * @file           : mesh.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/29
  ******************************************************************************
  */



#include "mesh.hpp"

void Mesh::loadMesh(const std::string &path) {

    // assimp read file
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);

    // check error
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }


}

void Mesh::processNode(aiNode *node, const aiScene *scene) {

}
