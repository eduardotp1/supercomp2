#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

static long num_steps = 100000000;
double step;

void funcao_rodando_em_paralelo(int i,int div,double step, double *sum) {
    double x,s;
    for (int j = div*i; j < div*(i+1); j++) {
        x = (j + 0.5) * step;
        s = s + 4.0 / (1.0 + x * x);
    }    
    *sum=s;
}


int main() {
    double pi = 0.0;
    step = 1.0 / (double)num_steps;
    int n_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> v(n_threads);
    std::vector<double> sum(n_threads);
    int div = num_steps/n_threads;
    double res;

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n_threads; i++) {
        v[i]=std::thread(funcao_rodando_em_paralelo,i,div,step, &sum[i]);
    }
    for  (int i = 0; i < n_threads; i++) {
        v[i].join();
        res+=sum[i];
    }

    pi = step * res;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::seconds> (end_time - start_time);
    
    std::cout << "O valor de pi calculado com " << num_steps << " passos levou ";
    std::cout << runtime.count() << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
}