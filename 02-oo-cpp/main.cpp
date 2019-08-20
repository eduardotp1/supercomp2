#include <iostream>
#include "experimento.hpp"
#include "log.hpp"
#include "pow3.hpp"
#include "mathpow3.hpp"
#include "sqrt.hpp"
#include "sum.hpp"


int main(){
    int n = 10000000;
    double time;

    time=0;
    Experimento *log = new MultiLog();
    log->gera_entrada(n);
    log->run();
    time = log->duration();
    std::cout << "Log Time: " << time << "\n";

    time=0;
    Experimento *pow3 = new MultiPow3();
    pow3->gera_entrada(n);
    pow3->run();
    time = pow3->duration();
    std::cout << "Pow3 Time: " << time << "\n";

    time=0;
    Experimento *mathpow3 = new MultiMathPow3();
    mathpow3->gera_entrada(n);
    mathpow3->run();
    time = mathpow3->duration();
    std::cout << "Math pow3 Time: " << time << "\n";

    time=0;
    Experimento *sqrt = new MultiSqrt();
    sqrt->gera_entrada(n);
    sqrt->run();
    time = sqrt->duration();
    std::cout << "Sqrt Time: " << time << "\n";

    time=0;
    Experimento *sum = new MultiSum();
    sum->gera_entrada(n);
    sum->run();
    time = sum->duration();
    std::cout << "Sum Time: " << time << "\n";
    
    if((double(*log) < 100)){
        std::cout << "log durou menos que 0.1s"<< "\n";
    }
    if((double(*pow3) < 100)){
        std::cout << "pow3 durou menos que 0.1s"<< "\n";
    }
    if((double(*mathpow3) < 100)){
        std::cout << "mathpow3 durou menos que 0.1s"<< "\n";
    }
    if((double(*sqrt) < 100)){
        std::cout << "sqrt durou menos que 0.1s"<< "\n";
    }
    if((double(*sum) < 100)){
        std::cout << "sum durou menos que 0.1s"<< "\n";
    }
    return 0;
}
