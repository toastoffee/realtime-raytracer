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
            m_cubeMaps[m_faces[i]] = std::make_shared<Texture2D>(data, width, height);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cube map texture failed to load at path: " << cubeMapDir + m_faces[i] << std::endl;
            stbi_image_free(data);
        }
    }

}



