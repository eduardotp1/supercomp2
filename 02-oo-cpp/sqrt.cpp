#include "sqrt.hpp"
#include <math.h>

void MultiSqrt::experiment_code() {
    for (int i = 0; i < this->n; i++) {
        this->arr[i] = sqrt(this->arr[i]);
    }
}