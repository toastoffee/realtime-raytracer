#include "path_tracer.hpp"
#include "sphere.hpp"

#include "skybox.hpp"
#include "material.hpp"
#include "triangle.hpp"
#include "mesh_tool.hpp"


int main() {

    std::shared_ptr<Scene> scene(new Scene());

    auto metal_left_mat = std::make_shared<Metal>(Color(0.5, 0.5, 0.5), 0.1f);
    auto lambertian_right_mat = std::make_shared<Lambertian>(Color(0.6, 0.8, 1,0));

//    auto sphere_left = new Sphere(Vec3(-0.5, 0, 1), 0.5f);
//    sphere_left->mat = metal_left_mat;
//    scene->AddObject(std::unique_ptr<Sphere>(sphere_left));
//
//    auto sphere_right = new Sphere(Vec3(0.5, 0, 1), 0.5f);
//    sphere_right->mat = lambertian_right_mat;
//    scene->AddObject(std::unique_ptr<Sphere>(sphere_right));


//    Vec3 a(-0.5, -0.5, 1);
//    Vec3 b(-0.5, 0.5, 1);
//    Vec3 c(0.5, 0.5, 1);
//    auto triangle = new Triangle(a, b, c);
//    triangle->mat = metal_left_mat;
//    scene->AddObject(std::unique_ptr<Triangle>(triangle));

//    auto cube = new MeshObject("../static/nanosuit/nanosuit.obj", Vec3(0, -8, 10), metal_left_mat);
//    auto cube = new MeshTool("../static/bunny.obj", Vec3(0.03, -0.1, 0.5), metal_left_mat);
//    cube->mat = metal_left_mat;
//    scene->AddObject(std::unique_ptr<MeshTool>(cube));

    MeshTool::LoadTrianglesToScene("../static/bunny.obj", Vec3(0.03, -0.1, 0.5), metal_left_mat, scene);

    std::unique_ptr<PathTracer> app(new PathTracer(scene.get()));

    app->MainLoop();

    return 0;
}
