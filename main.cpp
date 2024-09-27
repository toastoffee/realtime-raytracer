#include "path_tracer.hpp"
#include "sphere.hpp"

#include "skybox.hpp"
#include "material.hpp"


int main() {

    std::unique_ptr<Scene> scene(new Scene());

    auto metal_left_mat = std::make_shared<Metal>(Color(0.5, 0.5, 0.5), 0.3f);
    auto metal_right_mat = std::make_shared<Metal>(Color(0.5, 0.5, 0.4), 0.7f);

    auto sphere_left = new Sphere(Vec3(-0.5, 0, 1), 0.5f);
    sphere_left->mat = metal_left_mat;
    scene->AddObject(std::unique_ptr<Sphere>(sphere_left));

    auto sphere_right = new Sphere(Vec3(0.5, 0, 1), 0.5f);
    sphere_right->mat = metal_right_mat;
    scene->AddObject(std::unique_ptr<Sphere>(sphere_right));

    std::unique_ptr<PathTracer> app(new PathTracer(scene.get()));

    app->MainLoop();

    return 0;
}
