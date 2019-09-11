#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <thread>


void funcao_rodando_em_paralelo(int i,int div,double step, double *sum) {
    double x,s;
    for (int j = div*i; j < div*(i+1); j++) {
        x = (j + 0.5) * step;
        s = s + 4.0 / (1.0 + x * x);
    }    
    *sum=s;
}

double pi_threads_raiz(long steps){
    double pi = 0.0;
    double step = 1.0 / (double)steps;
    int n_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> v(n_threads);
    std::vector<double> sum(n_threads);
    int div = steps/n_threads;
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
    return pi;
}

double pi_seq(long steps){
    int i;
    double x, pi, sum = 0.0;
    double step = 1.0 / (double)steps;

    for (i = 0; i < steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }

    pi = step * sum;
    return pi;
}

double pi_omp_parallel(long steps){
    int i;
    double x, pi, res = 0.0;
    double step = 1.0 / (double)steps;
    double div = steps/omp_get_max_threads();
    std::vector<double> sum(omp_get_max_threads());

    #pragma omp parallel 
    {
        for (i = div*omp_get_thread_num(); i < div*(omp_get_thread_num()+1); i++) {
            x = (i + 0.5) * step;
            sum[omp_get_thread_num()] = sum[omp_get_thread_num()] + 4.0 / (1.0 + x * x);
        }
    }

    for  (int i = 0; i < omp_get_max_threads(); i++) {
        res+=sum[i];
    }

    pi = step * res;
    return pi;
}

double pi_omp_parallel_local(long steps){
    int i;
    double x, pi, res = 0.0;
    double step = 1.0 / (double)steps;
    double div = steps/omp_get_max_threads();
    std::vector<double> sum(omp_get_max_threads());

    #pragma omp parallel 
    {
        double s;
        for (i = div*omp_get_thread_num(); i < div*(omp_get_thread_num()+1); i++) {
            x = (i + 0.5) * step;
            s = s + 4.0 / (1.0 + x * x);
        }
        sum[omp_get_thread_num()]=s;
    }

    for  (int i = 0; i < omp_get_max_threads(); i++) {
        res+=sum[i];
    }

    pi = step * res;
    return pi;
}

double pi_atomic(double div, long id, double step) {
    double x, sum = 0.0;

    for (int i=div*id; i < div*(id+1); i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }

    return step * sum;
}

double pi_omp_parallel_atomic(long steps){
    int i;
    double x, pi, sum, res = 0.0;
    double step = 1.0 / (double)steps;
    double div = steps/omp_get_max_threads();

    #pragma omp parallel
    {
        #pragma omp atomic
        pi += pi_atomic(div, omp_get_thread_num(), step);
    }
    return pi;
}

double pi_omp_parallel_critical(long steps){
    int i;
    double x, pi, sum, res = 0.0;
    double step = 1.0 / (double)steps;
    double div = steps/omp_get_max_threads();

    #pragma omp parallel
    {
        double sum = pi_atomic(div, omp_get_thread_num(), step);
        #pragma omp critical
        pi +=sum; 
    }
    return pi;
}

double pi_omp_parallel_critical_errado(long steps){
    int i;
    double x, pi, sum, res = 0.0;
    double step = 1.0 / (double)steps;
    double div = steps/omp_get_max_threads();

    #pragma omp parallel
    {
        #pragma omp critical
        pi += pi_atomic(div, omp_get_thread_num(), step);
    }
    return pi;
}


double pi_omp_for(long steps){
    double x,  sum = 0.0;
    double step = 1.0 / (double)steps;

    #pragma omp parallel for reduction (+:sum) firstprivate(x)
    for (int i=0; i <steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    return step * sum;
}




int main() {
    static long steps=100000000;
    double pi;

    auto start_time = std::chrono::high_resolution_clock::now();
    pi=pi_seq(steps);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado em serie com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_threads_raiz(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com thread com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_parallel(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com omp com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_parallel_local(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com omp local com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_parallel_atomic(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com omp atomic com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_parallel_critical(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com omp critical com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_parallel_critical_errado(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com omp critical com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi=pi_omp_for(steps);
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << "O valor de pi calculado com for com " << steps << " passos levou ";
    std::cout << runtime << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;


    return 0;
}
