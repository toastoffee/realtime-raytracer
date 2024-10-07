/**
  ******************************************************************************
  * @file           : mesh_object.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/30
  ******************************************************************************
  */



#include "mesh_tool.hpp"
#include "math_tool.hpp"


void MeshTool::processNode(aiNode *node, const aiScene *aScene, const Vec3 &pos, const std::shared_ptr<Material> &mat, std::shared_ptr<Scene> &scene) {

    // process all meshes and load triangles
    for (unsigned int i = 0; i < node-> mNumMeshes; ++i) {
        aiMesh* aMesh = aScene->mMeshes[node->mMeshes[i]];
        auto mesh = convertMesh(aMesh, aScene);

        for (int j = 0; j < mesh->m_indices.size(); j += 3) {
            auto a = pos + mesh->m_vertices[j];
            auto b = pos + mesh->m_vertices[j+1];
            auto c = pos + mesh->m_vertices[j+2];

            auto face = new Triangle(a, b, c);
            face->mat = mat;
            scene->AddObject(std::unique_ptr<Triangle>(face));
        }

        delete mesh;
    }

    // repeat this process for all children nodes
    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], aScene, pos, mat, scene);
    }
}

Mesh *MeshTool::convertMesh(aiMesh *mesh, const aiScene *scene) {
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


void MeshTool::LoadTrianglesToScene(const std::string &path, const Vec3 &pos, const std::shared_ptr<Material> &mat,
                                    std::shared_ptr<Scene> &scene) {
    // assimp read file
    Assimp::Importer importer;
    const aiScene* aScene = importer.ReadFile(path, aiProcess_Triangulate);

    // check error
    if(!aScene || aScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !aScene->mRootNode){
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }

    processNode(aScene->mRootNode, aScene, pos, mat, scene);
}
