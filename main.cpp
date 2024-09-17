#include "render_window.hpp"
#include "canvas.hpp"
#include "camera.hpp"

int main() {

    RenderWindow window(1280, 720);

    int width = 0;
    int height = 256;

    Camera camera(Vec3::zero(), 16.f/9, 90.f, height);
    Color *data = camera.Render(width, height);

    Canvas canvas(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            canvas.WriteInPixel(data[i + j*width], i, j);
        }
    }

    while(window.BeginWindow()) {

        canvas.UpdateTex();
        canvas.Render();
        window.EndWindow();
    }

    return 0;
}
