#include "mathpow3.hpp"
#include <math.h>

void MultiMathPow3::experiment_code() {
    for (int i = 0; i < this->n; i++) {
        this->arr[i] = pow(this->arr[i], 3);
    }
}