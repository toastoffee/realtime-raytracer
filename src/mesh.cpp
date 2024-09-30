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


Mesh::Mesh(const std::vector<Vec3> &vertices, const std::vector<unsigned int> &indices)
 : m_vertices(vertices), m_indices(indices) { }
