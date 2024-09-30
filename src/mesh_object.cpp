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
    // assimp read file
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);

    // check error
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }

    processNode(scene->mRootNode, scene);
}

void MeshObject::processNode(aiNode *node, const aiScene *scene) {

    // process all meshes
    for (unsigned int i = 0; i < node-> mNumMeshes; ++i) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        m_meshes.push_back(convertMesh(mesh, scene));
    }

    // repeat this process for all children nodes
    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], scene);
    }
}

Mesh *MeshObject::convertMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vec3> vertices;
    std::vector<unsigned int> indices;

    // handle vertices
    for(unsigned int i = 0; i < mesh->mNumVertices; i++){
        Vec3 vertex(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        vertices.push_back(vertex);
    }

    // handle indices
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {

        aiFace face = mesh->mFaces[i];

        for (unsigned int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }

    return new Mesh(vertices, indices);
}

bool MeshObject::CheckHit(const Ray &ray, HitPayload &payload, double minRange, double maxRange) {
    return false;

}

MeshObject::MeshObject(const std::string &path) {
    loadMeshes(path);
}
