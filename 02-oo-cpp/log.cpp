#include "log.hpp"
#include <math.h>
#include "experimento.hpp"

void MultiLog::experiment_code() {
    for (int i = 0; i < this->n; i++) {
        this->arr[i] = log(this->arr[i]);
    }
}