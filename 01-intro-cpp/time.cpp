#include <iostream>
#include <cmath>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    int n;
    std::cin >> n;
    double *values = new double[n*2];

    for (int j=0;j<n*2;j++){
        if(j==0){
            std::cout<<"Digite "<<n<<" numeros para o Grupo 1"<<"\n";
        }
        if(j==n){
            std::cout<<"Digite "<<n<<" numeros para o Grupo 2"<<"\n";
        }
        std::cin>>values[j];
    }

    double res;
    for (int i = 0; i < n; i++) {
        res += pow(values[i] - values[i+(n)], 2.0);
    }
    

    /* usar values aqui */

    delete[] values;
    std::cout << "Euclidian: " << res<<"\n";

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = finish - start;
    std::cout<<"Time: "<<diff.count()*1000;
}