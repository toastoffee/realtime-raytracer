#include "path_tracer.hpp"
#include "sphere.hpp"


int main() {

    std::unique_ptr<Scene> scene(new Scene());

    scene->AddObject(std::unique_ptr<Sphere>(new Sphere(Vec3::forward(), 0.5f)));
    scene->AddObject(std::unique_ptr<Sphere>(new Sphere(Vec3::forward() + Vec3::right()*0.5f, 0.5f)));
    scene->AddObject(std::unique_ptr<Sphere>(new Sphere(Vec3::forward() + Vec3::left()*0.5f, 0.5f)));

    std::unique_ptr<PathTracer> app(new PathTracer(scene.get()));

    app->MainLoop();

    return 0;
}
