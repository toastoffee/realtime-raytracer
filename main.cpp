#include "render_window.hpp"
#include "canvas.hpp"

int main() {

    RenderWindow window(1280, 720);

    
    int width = 256;
    int height = 256;
    Canvas canvas(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            canvas.WriteInPixel({
                (double)i / (width-1),
                (double)j / (height-1),
                0.f,
                1.f,
            }, i, j);
        }
    }

    while(window.BeginWindow()) {

        canvas.UpdateTex();
        canvas.Render();
        window.EndWindow();
    }

    return 0;
}
