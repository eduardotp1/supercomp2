#ifndef COLLISION_H
#define COLLISION_H
#include <vector>

class Collision{
public:
~Collision();
    Collision(double w,double h, double mu_d, int N, int dt, int print_freq, int max_iter, std::vector<Rect>);
    
    double w;//largura
    double h;//altura
    double mu_d; //coeficiente de atrito
    int N; //quantidade de rect
    int dt;//representa o tamanho do passo de simulação
    int print_freq;//frequencia de print
    int max_iter; //numero maximo de iteracao
    std::vector<Rect> rect_vector;
    double a;
    std::vector<Rect> new_vector;
    bool stop;
    int iter;

    void wall_collide(void);
    void collide(void);
    void verify(void);
    void move(void);
    void movement(void);
    void run(void);
    };

#endif