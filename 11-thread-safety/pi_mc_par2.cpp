#include <stdio.h>
#include <omp.h>
#include <random>


static long num_trials = 10000000;

int main ()
{
   long Ncirc_total = 0;
   double pi, test, x, y;
   double r = 1.0; // radius of circle. Side of squrare is 2*r
   static long div = num_trials / 4;

   double time = omp_get_wtime();
   #pragma omp parallel private(x,y,test)
   {
      std::default_random_engine generator;
      std::uniform_real_distribution<double> distribution(-r,r);
      
      
      long Ncirc = 0;

      for(long i=0;i<div; i++)
      {
         x = distribution(generator);
         y = distribution(generator);

         test = x * x + y * y;

         if (test <= r*r) Ncirc++;
      }

      #pragma omp atomic
      Ncirc_total += Ncirc;
   }

   pi = 4.0 * ((double)Ncirc_total/(double)num_trials);

   printf("\n %ld trials, pi is %lf ",num_trials, pi);
   printf(" in %lf seconds\n",omp_get_wtime()-time);

   return 0;
}
	  
