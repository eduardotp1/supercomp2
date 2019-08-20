#include <iostream>
#include <random>
#include <math.h>
#include <chrono> 
#include <ostream>


double *gera_vetor(int n){
    double *arr=new double[n];
    for(int i=0;i<n;i++){
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(1.0, 2.0);
        arr[i]=dis(gen);
    }
    return arr;
}

void multi_log(double *arr, int size){
    for(int i=0;i<size;i++){
        arr[i]=log(arr[i]);
    }
}

void multi_sqrt(double *arr, int size){
    for(int i=0;i<size;i++){
        arr[i]=sqrt(arr[i]);
    } 
}

void multi_math_pow3(double *arr, int size){
    for(int i=0;i<size;i++){
        arr[i]=pow(arr[i],3);
    }
}

void multi_pow3(double *arr, int size){
    for(int i=0;i<size;i++){
        arr[i]=arr[i]*arr[i]*arr[i];
    }
}

void sum(double *arr, int size){
    double res=0;
    for(int i=0;i<size;i++){
        res=res+arr[i];
    }
}


int main(){
    int size;
    std::cin>>size;

    for(int i=1;i<size;i++){
        double *arr=new double[i];
        arr=gera_vetor(i);

        auto start_time =std::chrono::high_resolution_clock::now();
        sum(arr,i);
        auto sum_time =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = sum_time-start_time;
        std::cout<<"Tempo soma:"<< diff.count()*1000<<"\n";
        
        multi_log(arr,i);
        auto log_time =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = log_time-sum_time;
        std::cout<<"Tempo log:"<< diff1.count()*1000<<"\n";

        multi_math_pow3(arr,i);
        auto m_pow3_time =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = m_pow3_time-log_time;
        std::cout<<"Tempo pow using math:"<< diff2.count()*1000<<"\n";

        multi_pow3(arr,i);
        auto pow_time =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = pow_time-m_pow3_time;
        std::cout<<"Tempo pow:"<< diff3.count()*1000<<"\n";

        multi_sqrt(arr,i);
        auto sqrt_time =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff4 = sqrt_time-pow_time;
        std::cout<<"Tempo sqrt:"<< diff4.count()*1000<<"\n";



        delete[] arr;

    }

}
