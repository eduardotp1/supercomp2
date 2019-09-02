#include <iostream>
#include <random>
#include <math.h>
#include <chrono> 
#include <ostream>

double soma_positivos1(double *a, int n){
    double s;
    for(int i;i<n;i++){
        if(a[i]>0){
            s+=a[i];
        }
    }
    return s;
}

int main(){
    int n=10000000;
    double *arr=new double[n];
    for(int i=0;i<n;i++){
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(-10, 10);
        arr[i]=dis(gen);
    }

    auto start_time =std::chrono::high_resolution_clock::now();
    soma_positivos1(arr,n);
    auto end_time =std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    std::cout<<"Tempo soma:"<< diff.count()*1000<<"\n";
}