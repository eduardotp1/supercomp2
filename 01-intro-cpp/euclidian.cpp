#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin >> n;
    double *values = new double[n*2];

    for (int j=0;j<n*2;j++){
        if(j==0){
            std::cout<<"Digite "<<n<<"numeros para o Grupo 1";
        }
        if(j==n){
            std::cout<<"Digite "<<n<<"numeros para o Grupo 2";
        }
        std::cin>>values[j];
    }

    double res;
    for (int i = 0; i < n; i++) {
        res += pow(values[i] - values[i+(n)], 2.0);
    }
    

    /* usar values aqui */

    delete[] values;
    std::cout << "Euclidian: " << res;


}
