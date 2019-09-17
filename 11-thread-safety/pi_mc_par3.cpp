#include <stdio.h>
#include <omp.h>
#include <random>


static long num_trials = 10000000;

int main ()
{
    long i;long Ncirc = 0;
    double pi, test, x, y;
    double r = 1.0; // radius of circle. Side of squrare is 2*r

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-r,r);

    double time = omp_get_wtime();
    #pragma omp parallel for reduction (+:Ncirc) private(test, x, y)         
    for(i=0;i<num_trials; i++)
    {
        #pragma omp critical
        {
            x = distribution(generator);
            y = distribution(generator);
        }
        
        test = x * x + y * y;

        if (test <= r*r) Ncirc++;
    }

    pi = 4.0 * ((double)Ncirc/(double)num_trials);

    printf("\n %ld trials, pi is %lf ",num_trials, pi);
    printf(" in %lf seconds\n",omp_get_wtime()-time);

    return 0;
    }
        
