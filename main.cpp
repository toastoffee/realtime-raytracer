#include <iostream>
#include <math/vec3.hpp>


int main() {

    Vec3 v1(1, 0, 0);
    Vec3 v2(0, 1, 0);

    Vec3 v3 = Vec3::Cross(v1, v2);

    return 0;
}
