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
    if(Vec3::Angle(dir, Vec3::forward()) <= quarter_pi) {
        double t = 1.0f / dir.z();
        // point => (t * x, t * y, 1.0f)
        // (-1, -1) ~ (1, 1) => (0, 0) ~ (1, 1)
        // uv => ( (t*x+1)/2.0 , (t*y+1)/2.0 )
        double u = (t * dir.x() + 1.0f) / 2.0f;
        double v = (t * dir.y() + 1.0f) / 2.0f;

        return m_cubeMaps["front.jpg"]->Sample(u, v);
    }
    // back
    else if(Vec3::Angle(dir, Vec3::back()) <= quarter_pi) {
        double t = -1.0f / dir.z();

        double u = (t * dir.x() + 1.0f) / 2.0f;
        double v = (t * dir.y() + 1.0f) / 2.0f;

        return m_cubeMaps["back.jpg"]->Sample(u, v);
    }
    // right
    else if(Vec3::Angle(dir, Vec3::right()) <= quarter_pi) {
        double t = 1.0f / dir.x();

        double u = (t * dir.y() + 1.0f) / 2.0f;
        double v = (t * dir.z() + 1.0f) / 2.0f;

        return m_cubeMaps["right.jpg"]->Sample(u, v);
    }
    // right
    else if(Vec3::Angle(dir, Vec3::left()) <= quarter_pi) {
        double t = -1.0f / dir.x();

        double u = (t * dir.y() + 1.0f) / 2.0f;
        double v = (t * dir.z() + 1.0f) / 2.0f;

        return m_cubeMaps["left.jpg"]->Sample(u, v);
    }
    // up
    else if(Vec3::Angle(dir, Vec3::up()) <= quarter_pi) {
        double t = 1.0f / dir.y();

        double u = (t * dir.x() + 1.0f) / 2.0f;
        double v = (t * dir.z() + 1.0f) / 2.0f;

        return m_cubeMaps["top.jpg"]->Sample(u, v);
    }
    // up
    else if(Vec3::Angle(dir, Vec3::down()) <= quarter_pi) {
        double t = -1.0f / dir.y();

        double u = (t * dir.x() + 1.0f) / 2.0f;
        double v = (t * dir.z() + 1.0f) / 2.0f;

        return m_cubeMaps["bottom.jpg"]->Sample(u, v);
    }
    else {
        // return Magenta
        return {1.0f, 0.0f, 1.0f};
    }

}



