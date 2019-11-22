#include "rectangle.hpp"
#include "collision.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

Collision::Collision(double w, double h, double mu_d, double N, std::vector<Rectangle> rect_vector, double dt, double print_freq, double max_iter):w(w),h(h),mu_d(mu_d),accel(mu_d*9.8),N(N),rect_vector(rect_vector),rect_vector_next(rect_vector),dt(dt), print_freq(print_freq),max_iter(max_iter) {
    // w = w;
    // h = h;
    // mu_d = mu_d;
    // accel = mu_d*9.8;
    // N = N;
    // rect_vector = rect_vector;
    // rect_vector_next = rect_vector;
    // dt = dt;
    // print_freq = print_freq;
    // max_iter = max_iter;
    iter = 0;
    is_stable = false;
}
Collision::~Collision() {}

void Collision::stable() {
    double v;
    for (Rectangle &rect : rect_vector) {
        v = sqrt(pow(rect.velocity.first, 2) + pow(rect.velocity.second, 2));
        if (v > 0.0001) {
            return;
        }
    }
    is_stable = true;
}

void Collision::move() {
    for (Rectangle &rect : rect_vector_next) {
        rect.position.first = rect.position.first + (rect.velocity.first * dt);
        rect.position.second = rect.position.second + (rect.velocity.second * dt);

        if (rect.velocity.first != 0.0 || rect.velocity.second != 0.0) {
            double v = sqrt(pow(rect.velocity.first, 2) + pow(rect.velocity.second, 2));
            double theta = atan2(rect.velocity.second,rect.velocity.first);
            v = v - (accel * dt);
            if (v <= 0.0) {
                v = 0.0;
            }
            rect.velocity.first  = v * cos(theta);
            rect.velocity.second = v * sin(theta);
        }
    }
}

void Collision::wall() {

    for (Rectangle &rect : rect_vector_next) {
        if (rect.position.first + rect.wr >= w) {
            rect.collided = true;
            rect.velocity.first = -rect.velocity.first;

        } else if (rect.position.first < 0) {
            rect.collided = true;
            rect.velocity.first = -rect.velocity.first;
        }

        if (rect.position.second >= h) {
            rect.collided = true;
            rect.velocity.second = -rect.velocity.second;

        } else if (rect.position.second - rect.hr < 0) {
            rect.collided = true;
            rect.velocity.second = -rect.velocity.second;
        }
    }
}

void Collision::rect_collision() {
    for (int i = 0; i < N; i++)  {
        for (int j = i + 1; j < N; j++) {
            
            Rectangle &A = rect_vector[i];
            Rectangle &B = rect_vector[j];
            Rectangle &A_next = rect_vector_next[i];
            Rectangle &B_next = rect_vector_next[j];

            if (A.id != B.id){
                if (A.position.first < B.position.first + B.wr && A.position.first + A.wr  > B.position.first){
                    if (A.position.second > B.position.second - B.hr && A.position.second - A.hr < B.position.second) {
                        A_next.velocity.first = ((A.velocity.first * (A.m - B.m)) + (2 * B.velocity.first * B.m) / (A.m + B.m));
                        B_next.velocity.first = ((B.velocity.first * (B.m - A.m)) + (2 * A.velocity.first * A.m) / (B.m + A.m));
                        A_next.velocity.second = ((A.velocity.second * (A.m - B.m)) + (2 * B.velocity.second * B.m) / (A.m + B.m));
                        B_next.velocity.second = ((B.velocity.second * (B.m - A.m)) + (2 * A.velocity.second * A.m) / (B.m + A.m));

                        A_next.collided = true;
                        B_next.collided = true;
                    }
                }
            }
        }
    }
}

void Collision::check() {
    for (int i = 0; i < N; i++)  {
        if (rect_vector_next[i].collided == true) {
            rect_vector_next[i].position.first = rect_vector[i].position.first;
            rect_vector_next[i].position.second = rect_vector[i].position.second;
            rect_vector_next[i].collided = false;
        }
    }
    rect_vector = rect_vector_next;
}


void Collision::run() {
    auto start = std::chrono::high_resolution_clock::now();
    while(iter < max_iter && !is_stable) {
        move();
        wall();
        rect_collision();
        check();
        stable();

        if (int(iter) % int(print_freq) == 0) {
            std::cout << iter << "\n";

            // std::cout<< rect_vector[0].position.first << "\n";
            for (Rectangle &rect : rect_vector){
                rect.print_rect();
            }
            std::cout << "\n";
        }

        iter += 1;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = (finish - start);
    duration = elapsed.count();

    std::cout<<"Demorou: " << duration << "\n";
    std::cout<<"Quantidade de objetos: " << N << "\n";
}