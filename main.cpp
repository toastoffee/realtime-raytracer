#include "path_tracer.hpp"
#include "sphere.hpp"

#include "skybox.hpp"

int main() {

//    std::unique_ptr<Scene> scene(new Scene());
//
//    scene->AddObject(std::unique_ptr<Sphere>(new Sphere(Vec3(0, 0, 1), 0.5f)));
//    scene->AddObject(std::unique_ptr<Sphere>(new Sphere(Vec3::down()*100.5, 100.f)));
//
//    std::unique_ptr<PathTracer> app(new PathTracer(scene.get()));
//
//    app->MainLoop();

    SkyBox skyBox("../static/skybox/");

    return 0;
}
