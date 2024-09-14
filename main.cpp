#include "render_window.hpp"


int main() {

    RenderWindow window(1280, 720);

    while(window.BeginWindow()) {

        window.EndWindow();
    }

    return 0;
}
