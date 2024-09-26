#include "path_tracer.hpp"
#include "sphere.hpp"

#include "skybox.hpp"
#include "material.hpp"

int main() {

    std::unique_ptr<Scene> scene(new Scene());

    auto metal_mat = std::make_shared<Metal>(Color(0.5, 0.5, 0.5), 0.0f);

    auto sphere = new Sphere(Vec3(-0.5, 0, 1), 0.5f);
    sphere->mat = metal_mat;
    scene->AddObject(std::unique_ptr<Sphere>(sphere));

    auto ground = new Sphere(Vec3(0.5, 0, 1), 0.5f);
    ground->mat = metal_mat;
    scene->AddObject(std::unique_ptr<Sphere>(ground));



    std::unique_ptr<PathTracer> app(new PathTracer(scene.get()));

    app->MainLoop();

    return 0;
}
