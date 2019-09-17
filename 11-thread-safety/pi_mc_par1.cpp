#include <stdio.h>
#include <omp.h>
#include <random>
#include <vector>


static long num_trials = 10000000;

int main ()
{
   long i,j;  long Ncirc = 0;
   double pi, test;
   double r = 1.0;   // radius of circle. Side of squrare is 2*r 

   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(-r,r);
   
   std::vector<double> x(num_trials);
   std::vector<double> y(num_trials);
   
   double time = omp_get_wtime();

   
//    #pragma omp parallel for reduction (+:Ncirc) private(test) 
   for(i=0;i<num_trials; i++)
   {
      x[i] = distribution(generator);
      y[i] = distribution(generator);
    }

   #pragma omp parallel for reduction (+:Ncirc) private(test) 
   for(j=0;j<num_trials; j++)
   {
      test = x[j] * x[j] + y[j] * y[j];

      if (test <= r*r) Ncirc++;
    }

    pi = 4.0 * ((double)Ncirc/(double)num_trials);

    printf("\n %ld trials, pi is %lf ",num_trials, pi);
    printf(" in %lf seconds\n",omp_get_wtime()-time);

    return 0;
}
	  
