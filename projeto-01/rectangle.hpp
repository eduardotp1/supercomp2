#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <utility>

class Rectangle {
    private:
    ;
    public:
        Rectangle(double m, double wr, double hr, double x, double y, double vx, double vy, double id);
        ~Rectangle();

        double id, collided, m, wr, hr; 
        std::pair<double, double> position;
        std::pair<double, double> velocity; 

        void print_rect(void); 
};

#endif