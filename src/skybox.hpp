/**
  ******************************************************************************
  * @file           : skybox.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/25
  ******************************************************************************
  */



#ifndef REALTIME_RAYTRACER_SKYBOX_HPP
#define REALTIME_RAYTRACER_SKYBOX_HPP

#include <string>
#include <map>

#include <texture2d.hpp>

class SkyBox {
private:
    std::vector<std::string> m_faces = {
        "right.jpg",
        "left.jpg",
        "top.jpg",
        "bottom.jpg",
        "front.jpg",
        "back.jpg"
    };

    std::map<std::string, std::shared_ptr<Texture2D> > m_cubeMaps;

    void loadCubeMap(const std::string& cubeMapDir);

public:
    explicit SkyBox(const std::string& cubeMapDir);
};


#endif //REALTIME_RAYTRACER_SKYBOX_HPP
