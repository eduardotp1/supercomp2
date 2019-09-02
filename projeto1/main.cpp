#include "rect.hpp"
#include "collision.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

int main(){
    double w, h, mu_d, m, wr, hr, x, y, vx, vy;
    int N, dt, print_freq, max_iter;
    auto start = std::chrono::high_resolution_clock::now(); 
    std::cin >> w >> h >> mu_d >> N;
    std::vector<Rect> rect_vector;
    for(int i = 0; i < N; i++) {
        std::cin >> m >> wr >> hr;
        std::cin >> x >> y >> vx >> vy;
        rect_vector.push_back(Rect(i, m, wr, hr, x, y, vx, vy));
    }
    std::cin >> dt >> print_freq >> max_iter;

    Collision coll = Collision(w, h, mu_d, N, dt, print_freq, max_iter,rect_vector);
    coll.run();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    double time = diff.count();
    std::cout << time;
}