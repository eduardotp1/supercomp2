#include "pow3.hpp"

void MultiPow3::experiment_code() {
    for (int i = 0; i < this->n; i++) {
        this->arr[i] = this->arr[i] * this->arr[i] * this->arr[i];
    }
}