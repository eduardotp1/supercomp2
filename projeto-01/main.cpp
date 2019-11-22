#include "rectangle.hpp"
#include "collision.hpp"

#include <iostream>
#include <utility>
#include <vector>

int main() {
    double w, h, mu_d, N; 
    double m, wr, hr, x, y, vx, vy;
    double dt, print_freq, max_iter;

    std::cin >> w; 
    std::cin >> h;
    std::cin >> mu_d;
    std::cin >> N;

    std::vector<Rectangle> rect_vector; 
    for(int i = 0; i < N; i++) {
        std::cin >> m >> wr >> hr >> x >> y >> vx >> vy;
        rect_vector.push_back(Rectangle(m, wr, hr, x, y, vx, vy, i));
    }
    std::cin >> dt >> print_freq >> max_iter;

    Collision collision = Collision(w, h, mu_d, N, rect_vector, dt, print_freq, max_iter);
    collision.run();

    return 0;
}