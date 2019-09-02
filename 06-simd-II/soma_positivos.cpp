#include "experimentSumPositives.hpp"
#include <iostream>
#include <chrono>

#include <x86intrin.h> //Extensoes SSE
#include <bits/stdc++.h> //Bibliotecas STD

#ifdef __AVX__

void SomaPositivo::experiment_code() {;
    __m256d sum = _mm256_setzero_pd();

    for(int i = 0; i < n; i+= 4) {
        __m256d vec = _mm256_loadu_pd(&arr[i]);
        __m256d inv = _mm256_xor_pd(vec, _mm256_set1_pd(-0.0));
        __m256d masked = _mm256_maskload_pd(&arr[i], _mm256_castpd_si256(inv));
        sum = _mm256_add_pd(sum, masked);
    }

    double* iterator = (double *) &sum;
    double result = 0;
    for(int i = 0; i < 4; i++) {
        result += iterator[i];
    }
    this->sum = result;
}

#else

void SomaPositivo::experiment_code() {
    double result = 0;
    for (int i = 0; i < n; i++) {
        (arr[i] > 0) ? result += arr[i] : 0.0;
    }
    this->sum = result;
}

#endif