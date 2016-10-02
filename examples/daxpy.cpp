/*
    This file is part of the example codes which have been used
    for the "Code Optmization Workshop".
    
    Copyright (C) 2016  Fabio Baruffa <fbaru-dev@gmail.com>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//To compile icpc -O3 -xAVX -qopenmp daxpy.cpp -o daxpy.x

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


                                    
