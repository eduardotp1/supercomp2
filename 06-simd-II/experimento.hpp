#ifndef EXPERIMENTO_H
#define EXPERIMENTO_H

class Experimento {
    public:
        Experimento(void);
        double *gera_entrada(int n);
        double duration();
        int n;
        double *arr;
        double time;
        virtual void experiment_code()=0;
        void run();
        operator double();
        bool operator < (Experimento *);
        bool operator < (double);  
};


#endif