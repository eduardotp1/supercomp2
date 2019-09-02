#include "rect.hpp"
#include "collision.hpp"
#include <iostream>
#include <vector>
#include <cmath>

Collision::Collision(double w,double h, double mu_d, int N, int dt, int print_freq, int max_iter, std::vector<Rect> rect_vector){
    w=w;
    h=h;
    mu_d=mu_d;
    N=N;
    dt=dt;
    print_freq=print_freq;
    max_iter=max_iter;
    rect_vector=rect_vector;
    a=mu_d*9.8;
    new_vector=rect_vector;
    stop=false;
    iter=0;
}
Collision::~Collision(){}

void Collision::wall_collide(){
    //colisao parede
    for (Rect &rect : new_vector) {
        if (rect.x + rect.wr >= w || rect.x <= 0) {
            rect.invert = true;
            rect.vx = -rect.vx;
        }

        if (rect.y >= h || rect.y - rect.hr <= 0) {
            rect.invert = true;
            rect.vy = -rect.vy;
        }
    }
}

void Collision::collide(){
    //colisao entre retangulos
    for (int i = 0; i < N; i++)  {
        for (int j = i + 1; j < N; j++) {
            Rect &rec1 = rect_vector[i];
            Rect &rec2 = rect_vector[j];
            Rect &new_rec1 = new_vector[i];
            Rect &new_rec2 = new_vector[j];
            double vrx = rec1.vx - rec2.vx;
            double vry = rec1.vy - rec2.vy;

            if ((rec1.x <= rec2.x <= rec1.x + rec1.wr) && (rec1.y >= rec2.y >= rec1.y - rec1.hr)) {
                new_rec1.vx = vrx*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vx = 2*vrx*rec1.m/(rec1.m + rec2.m);
                new_rec1.vy = vry*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vy = 2*vry*rec1.m/(rec1.m + rec2.m);

                new_rec1.invert = true;
                new_rec2.invert = true;
            }

            else if ((rec1.x <= rec2.x <= rec1.x + rec1.wr) && (rec1.y >= rec2.y - rec2.hr >= rec1.y - rec1.hr)) {
                new_rec1.vx = vrx*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vx = 2*vrx*rec1.m/(rec1.m + rec2.m);
                new_rec1.vy = vry*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vy = 2*vry*rec1.m/(rec1.m + rec2.m);

                new_rec1.invert = true;
                new_rec2.invert = true;
            }

            else if ((rec1.x <= rec2.x + rec2.wr <= rec1.x + rec1.wr) && (rec1.y >= rec2.y - rec2.hr >= rec1.y - rec1.hr)) {
                new_rec1.vx = vrx*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vx = 2*vrx*rec1.m/(rec1.m + rec2.m);
                new_rec1.vy = vry*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vy = 2*vry*rec1.m/(rec1.m + rec2.m);

                new_rec1.invert = true;
                new_rec2.invert = true;
            }

            else if ((rec1.x <= rec2.x + rec2.wr <= rec1.x + rec1.wr) && (rec1.y >= rec2.y >= rec1.y - rec1.hr)) {
                new_rec1.vx = vrx*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vx = 2*vrx*rec1.m/(rec1.m + rec2.m);
                new_rec1.vy = vry*(rec1.m - rec2.m)/(rec1.m + rec2.m);
                new_rec2.vy = 2*vry*rec1.m/(rec1.m + rec2.m);

                new_rec1.invert = true;
                new_rec2.invert = true;
            }
        }
    }
}

void Collision::verify() {
    for (int i = 0; i < N; i++)  {
        if (new_vector[i].invert == true) {
            new_vector[i].x = rect_vector[i].x;
            new_vector[i].y = rect_vector[i].y;
            new_vector[i].invert = false;
        }
    }
    rect_vector = new_vector;
}


void Collision::move() {
    for (Rect &r : new_vector) {
        r.x = r.x + (r.vx * dt);
        r.y = r.y + (r.vy * dt);

        if (r.vx != 0.0 || r.vy != 0.0) {
            double v = sqrt(pow(r.vx, 2) + pow(r.vy, 2));
            double t = atan(r.vy/r.vx);
            v = v - (a * dt);
            if (v <= 0.0) {
                v = 0.0;
            }
            r.vx = v * cos(t);
            r.vy = v * sin(t);
        }
    }
}

void Collision::movement() {
    for (Rect &r : new_vector) {
        double v = sqrt(pow(r.vx, 2) + pow(r.vy, 2));
        if (v > 0.0001) {
            stop=false;
        }
    }
    stop=true;
}

void Collision::run() {
    while(iter < max_iter && !stop) {
        move();
        wall_collide();
        collide();
        verify();
        movement();

        iter += 1;

        if (int(iter) % int(print_freq) == 0) {
            std::cout << iter << "\n";
            for (Rect &r : rect_vector){
                std::cout << r.x << " " << r.y << " " << r.vx << " " << r.vy << " " << "\n";
            }
        }
    }
}