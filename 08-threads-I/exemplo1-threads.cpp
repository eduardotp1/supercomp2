#include <thread>
#include <iostream>
#include <vector>


void funcao_rodando_em_paralelo(int a, int *b) {
    std::cout << "a=" << a << std::endl;
    *b=a*a;
}


int main() {
    int n_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> v(n_threads);
    std::vector<int> b(n_threads);
    std::cout << "Number of Threads: " << n_threads << std::endl;

    // Cria thread e a executa.
    // Primeiro argumento é a função a ser executada.
    
    // Os argumentos em seguida são passados diretamente
    // para a função passada no primeiro argumento.

    for(int i =0; i<n_threads;i++){
        v[i]=std::thread(funcao_rodando_em_paralelo, i, &b[i]);
    }
    for(int i =0; i<n_threads;i++){
        v[i].join();
        std::cout << "i=" << b[i] << std::endl;
    }


    // std::thread t1(funcao_rodando_em_paralelo, 0, &b);

    // std::thread t2(funcao_rodando_em_paralelo, 1, &b);

    // std::thread t3(funcao_rodando_em_paralelo, 2, &b);

    // std::thread t4(funcao_rodando_em_paralelo, 3, &b);

    
    
    // Espera até que a função acabe de executar.
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
}
