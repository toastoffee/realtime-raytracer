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

#include "vec3.hpp"

#include <vector>

struct TriangleFace {

};

class Mesh {
public:
    std::vector<Vec3> m_vertices;
    std::vector<unsigned int> m_indices;

public:
    Mesh(const std::vector<Vec3> &vertices, const std::vector<unsigned int> &indices);


};



#endif //REALTIME_RAYTRACER_MESH_HPP
