#include <omp.h>
#include <iostream>

int main() {
    std::cout << "I think";
	
	#pragma omp parallel
	{

		#pragma omp master
		{
			#pragma omp task
			std::cout << " race";
			#pragma omp task
			std::cout << " car";
		}
	}

    std::cout << "s are fun\n";
}