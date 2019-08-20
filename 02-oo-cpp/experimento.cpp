#include "experimento.hpp"
#include <iostream>
#include <random>
#include <math.h>
#include <chrono> 
#include <ostream>

Experimento::Experimento() {
}

double *Experimento::gera_entrada(int n){
    double *arr=new double[n];
    for(int i=0;i<n;i++){
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(1.0, 2.0);
        arr[i]=dis(gen);
    }
    this->arr = arr;
    this->n = n;
    return arr;
}

double Experimento::duration() {
    // auto start =std::chrono::high_resolution_clock::now();
    // //tenho que chamar a funcao aqui
    // auto end =std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> time = end-start;
    return this->time;
}

void Experimento::run() {
    auto start =std::chrono::high_resolution_clock::now();
    this->experiment_code();
    auto end =std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    this->time = diff.count();
}

Experimento::operator double() {
    return this->duration();
}

bool Experimento::operator < (Experimento *e) {
    if(e->time < this->time && e->n == this->n){
        return true;
    }
    return false;
}

bool Experimento::operator < (double time) {
    return this->time < time;
}