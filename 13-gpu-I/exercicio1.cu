#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

int main() {

    thrust::host_vector<double> host;
    double s;

    thrust::device_vector<double> dev(host); 

    while (!std::cin.eof()) {
        std::cin >> s;
        host.push_back(s);
    }

    double inf = std::numeric_limits<double>::infinity();

    auto start = high_resolution_clock::now();
    thrust::device_vector<double> dev(host);    
    auto end = high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cerr << " Tempo de copia para GPU" << runtime.count() << std::endl;

    // parte 2-reduce

    start = high_resolution_clock::now();

    double total = thrust::reduce(dev.begin(), dev.end(), (double) 0, thrust::plus<double>()) / host.size();
    double lowest_historical = thrust::reduce(dev.begin(), dev.end(), inf, thrust::minimum<double>());
    double highest_historical = thrust::reduce(dev.begin(), dev.end(), (double) 0, thrust::maximum<double>());
    double anual = thrust::reduce(dev.begin(), dev.begin()+365, (double) 0, thrust::plus<double>()) / 365;   
    double lowest_year = thrust::reduce(dev.begin(), dev.begin()+365, inf, thrust::minimum<double>());
    double highest_year = thrust::reduce(dev.begin(), dev.begin()+365, (double) 0, thrust::maximum<double>());
    end = high_resolution_clock::now();

    std::cout << "Média histórica " << mean_historical << std::endl;
    std::cout << "Média último ano " << mean_year << std::endl;
    std::cout << "Menor histórico " << lowest_historical << std::endl;
    std::cout << "Maior histórico " << highest_historical << std::endl;
    std::cout << "Menor último ano " << lowest_year << std::endl;
    std::cout << "Maior último ano " << highest_year << std::endl;
    
    runtime = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cerr << " Tempo de copia para GPU" << runtime.count() << std::endl;

    }