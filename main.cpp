#include "path_tracer.hpp"

int main() {

    std::unique_ptr<PathTracer> app(new PathTracer());

    app->MainLoop();

    return 0;
}
