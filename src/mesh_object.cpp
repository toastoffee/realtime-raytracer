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
#include "math_tool.hpp"

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
    double tNear = infinity;
    HitPayload payloadNear;

    for (auto triangle : m_triangles) {
        // if hit
        if(triangle.CheckHit(ray, payloadNear, minRange, maxRange)) {
            if(payloadNear.t < tNear) {
                tNear = payloadNear.t;
                payload = payloadNear;
            }
        }
    }

    return tNear != infinity;
}

MeshObject::MeshObject(const std::string &path, const Vec3 &pos, const std::shared_ptr<Material> &material) : m_pos(pos) {
    loadMeshes(path);

    for (auto mesh : m_meshes) {
        for (int i = 0; i < mesh->m_indices.size(); i += 3) {
            auto a = m_pos + mesh->m_vertices[i];
            auto b = m_pos + mesh->m_vertices[i+1];
            auto c = m_pos + mesh->m_vertices[i+2];

            Triangle face(a, b, c);
            face.mat = material;
            m_triangles.push_back(face);
        }
    }
}
