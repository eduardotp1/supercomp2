#ifndef RECT_H
#define RECT_H

class Rect {
public:
    Rect(int id, double m, double wr, double hr, double x, double y, double vx, double vy);
    int id;
    double m;//massa do retangulo
    double wr;//largura
    double hr;//altura
    double x, y;//posição inicial
    double vx, vy;//velocidade inicial
    bool invert;
    ~Rect();
};

#endif


