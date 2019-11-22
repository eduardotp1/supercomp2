#include "rectangle.hpp"
#include <iostream>
#include <utility>

Rectangle::Rectangle(double m, double w, double h, double x, double y, double vx, double vy, double n) {
    m = m;
    wr = w;
    hr = h;
    position = std::pair<double, double>(x, y);
    velocity = std::pair<double, double>(vx, vy);
    id = n;
    collided = false;
}
Rectangle::~Rectangle() {}

void Rectangle::print_rect() {
    std::cout << position.first << " " << position.second << " " << velocity.first << " " <<  velocity.second << "\n";
}