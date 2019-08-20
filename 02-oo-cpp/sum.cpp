#include "sum.hpp"

void MultiSum::experiment_code() {
    res = 0;
    for (int i = 0; i < this->n; i++) {
        res += this->arr[i];
    }
    return;
}