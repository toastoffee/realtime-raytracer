/**
  ******************************************************************************
  * @file           : skybox.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/25
  ******************************************************************************
  */


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stbi/stb_image.h>

#include <iostream>
#include <memory>

#include "skybox.hpp"
#include "math_tool.hpp"

SkyBox::SkyBox(const std::string& cubeMapDir)
: m_cubeMaps() {
    loadCubeMap(cubeMapDir);
}

void SkyBox::loadCubeMap(const std::string& cubeMapDir) {

    int width, height, nrChannels;
    for (unsigned int i = 0; i < m_faces.size(); i++)
    {
        unsigned char *data = stbi_load((cubeMapDir + m_faces[i]).c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            m_cubeMaps[m_faces[i]] = std::make_shared<Texture2D>(data, width, height, nrChannels);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cube map texture failed to load at path: " << cubeMapDir + m_faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
}

Color SkyBox::Sample(const Vec3 &dir) {

    double quarter_pi = PI / 4.0f;

    // forward
    if(dir.z() > 0.0f) {
        double t = 0.5f / dir.z();
        double intersect_u = t * dir.x();
        double intersect_v = t * dir.y();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
            && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["front.jpg"]->Sample(u, v);
        }
    }

    // back
    if(dir.z() <= 0.0f) {
        double t = -0.5f / dir.z();
        double intersect_u = t * dir.x();
        double intersect_v = t * dir.y();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
           && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["back.jpg"]->Sample(u, v);
        }
    }

    // right
    if(dir.x() > 0.0f) {
        double t = 0.5f / dir.x();
        double intersect_u = t * dir.z();
        double intersect_v = t * dir.y();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
           && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["right.jpg"]->Sample(1.0f - u, v);
        }
    }

    // left
    if(dir.x() <= 0.0f) {
        double t = -0.5f / dir.x();
        double intersect_u = t * dir.z();
        double intersect_v = t * dir.y();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
           && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["left.jpg"]->Sample(u, v);
        }
    }

    // up
    if(dir.y() <= 0.0f) {
        double t = 0.5f / dir.y();
        double intersect_u = t * dir.x();
        double intersect_v = t * dir.z();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
           && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["top.jpg"]->Sample(1.0f-u, 1.0f-v);
        }
    }

    // bottom
    if(dir.y() > 0.0f) {
        double t = -0.5f / dir.y();
        double intersect_u = t * dir.x();
        double intersect_v = t * dir.z();

        if(intersect_u >= -0.5f && intersect_u <= 0.5f
           && intersect_v >= -0.5f && intersect_v <= 0.5f) {
            double u = (intersect_u + 0.5f) / 1.0f;
            double v = (intersect_v + 0.5f) / 1.0f;

            return m_cubeMaps["bottom.jpg"]->Sample(u, v);
        }
    }

    // return Magenta
    return {1.0f, 0.0f, 1.0f};
}



