#include <thrust/device_vector.h>
#include <thrust/reduce.h>
#include <thrust/functional.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <iomanip>
#include <cuda_runtime.h>
#include <thrust/host_vector.h>
#include "curand.h"
#include "curand_kernel.h"
#include <cmath>


#define BLOCK_SIZE 32
#define ITERS 100000

__global__ void calc_dist(double *X, double *Y, double *dist, int N) {
    int i = blockIdx.y*blockDim.y+threadIdx.y;
    int j = blockIdx.x*blockDim.x+threadIdx.x;

    dist[i*N+j] = sqrt(pow((X[i] - X[j]), 2) + pow((Y[i] - Y[j]), 2));
}

__global__ void random_sol(int *solutions, double *costs, double *distances, int N, int nSols) {
    int i = blockIdx.x*blockDim.x+threadIdx.x;


    double cost = 0; 


    for (int k = 0; k < N; k++) {
        solutions[i * N + k] = k;
    }
    
    curandState_t st;
    curand_init(0, i, 0, &st);
    int idx;

    for (int k = 1; k < N; k++){
        idx = (int) ((N-k) * curand_uniform(&st) + k); 

        int tmp = solutions[i * N + k];
        solutions[i * N + k] = solutions[i * N + idx];
        solutions[i * N + idx] = tmp;

        cost += distances[solutions[i * N + k-1] * N + solutions[i * N + k]];
    }

    cost += distances[solutions[i * N] * N + solutions[i * N + N-1]]; 

    costs[i] = cost;

    // for (int k=0; k<i;k++){
    //     for (int j=0;j<i;j++){
    //         if costs[k]<costs[j]{

    //         }
    //     }
    // }

}

int main() {
    int N; std::cin >> N;
    thrust::host_vector<double> host_x(N);
    thrust::host_vector<double> host_y(N);

    double x, y;
    for (int i = 0; i < N; i++) {
        std::cin >> x; 
        std::cin >> y;
        host_x[i] = x;
        host_y[i] = y;
    }

    //copia as coisas para a gpu
    thrust::device_vector<double> dev_x(host_x);
    thrust::device_vector<double> dev_y(host_y);
    thrust::device_vector<double> dev_points_distance(N * N);

    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid(ceil(double N / double threads.x), ceil(double N / double threads.y));

    calc_dist<<<grid,threads>>>(thrust::raw_pointer_cast(dev_x.data()), thrust::raw_pointer_cast(dev_y.data()), thrust::raw_pointer_cast(dev_points_distance.data()), N);


    double nSols = 1024;
    int gpu_threads = 1024;
    
    thrust::device_vector<int> dev_solutions(nSols * N); 
    thrust::device_vector<double> dev_costs(nSols); 


    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, NULL);
    
    random_sol<<<ceil((double) nSols/gpu_threads), gpu_threads>>>(thrust::raw_pointer_cast(dev_solutions.data()), thrust::raw_pointer_cast(dev_costs.data()), thrust::raw_pointer_cast(dev_points_distance.data()), N, nSols);

    cudaEventRecord(stop, NULL);
    cudaEventSynchronize(stop);
    float msecTotal = 0.0f;
    cudaEventElapsedTime(&msecTotal, start, stop);

    thrust::device_vector<double>::iterator iter = thrust::min_element(dev_costs.begin(), dev_costs.end());
    int position = iter - dev_costs.begin();
    double min_val = *iter;


    std::cout << min_val;
    std::cout << " 0" << std::endl;

    for (int i = position * N; i < position * N + N; i++) {
        std::cout << dev_solutions[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}