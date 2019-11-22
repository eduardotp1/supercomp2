#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

class Collision {
    private:
    ;
    public:
        Collision(double w, double h, double mu_d, double N, std::vector<Rectangle> rect_vector, double dt, double print_freq, double max_iter);
        ~Collision();

        double w, h, mu_d, accel, N;
        double dt, print_freq, max_iter;
        std::vector<Rectangle> rect_vector;
        std::vector<Rectangle> rect_vector_next;
        double iter;
        bool is_stable;
        double duration;

        void move(void);
        void wall(void);
        void rect_collision(void);
        void check(void);
        void stable(void);
        void run(void);
};

#endif