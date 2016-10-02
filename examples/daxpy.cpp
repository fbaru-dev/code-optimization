#include <iostream>
#include "cpu_time.hpp"

double daxpy(double* __restrict__ y,
       const double* __restrict__ x,
       const double alpha,
       const int array_size,
       const int niter);

int main(int argc, char** argv)
{
        const int N = 1000000;
        const int niter = 5000;
        const double alpha = 3.0;

        double *x, *y;

        x = new double[N];
        y = new double[N];

#pragma omp parallel for        
        for(int i=0; i<N; i++)
        {
                x[i] = 2.0;
                y[i] = 1.0;
        }

        double t = daxpy(y,x,alpha,N,niter);

        double flops = 2.0 * double(N) * double(niter);

        std::cout << "Total time: " << t << " s" << std::endl;
        std::cout << "Total time/iter: " << t/niter << " s" << std::endl;
        std::cout << "Performance: " << 1e-9*flops/t << " GFlops/s" << std::endl;
    
        delete [] x;
        delete [] y;

        return 0;
}

double daxpy(double* __restrict__ y,
              const double* __restrict__ x,
              const double alpha,
              const int array_size,
              const int niter)
{
        int i,j;
        CPUTime t;
        double time;

        time = t.start();
        for(i=0; i<niter; ++i)
        {
#pragma omp parallel for
          for (j=0; j<array_size; j++)
             y[j] += alpha * x[j];
        }
        time = t.stop() - time;

        return time;
}


                                    
