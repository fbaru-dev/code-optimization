/*
    This file is part of the example codes which have been used
    for the "Code Optmization Workshop".
      
    This is a full vector TRIAD (a[i] =  b[i] + c[i] * d[i]).
    Every core runs its own, independent triad benchmark.
    
    Part of the idea has been taken from G. Hager, which is
    one of the likwid tool developer
    https://github.com/RRZE-HPC/likwid
    
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
	

//To compile the code: icpc -qopenmp -O3 triad.cpp -o triad.x

#ifdef _OPENMP
#include <omp.h>
#endif

#include "cpu_time.hpp"
#include "allocate.hpp"
#include <iostream>
#include <omp.h>

double triad(double* __restrict__ a,
       const double* __restrict__ b,
       const double* __restrict__ c,
       const double* __restrict__ d,
       const int array_size,
       const int niter);

int main(int argc, char** argv) 
{
    int i,j,k,l;
    double *a,*b,*c,*d;
    double wtime;
    int niter;
    int nthreads;
    double mflops;
    double mbytes;
    bool finish = false;
    int offset = 0;
    
    if (argc < 2)
    {
        printf("Usage: ./triad.x <size>\n");
        exit(EXIT_FAILURE);
    }
    int size = atoi(argv[1]);
    
    #pragma omp parallel private(k,j,a,b,c,d) reduction(+:wtime)
    {
      allocate_align(&a, 2*size+offset, 0.0);
      allocate_align(&b, 2*size+offset, 1.0);
      allocate_align(&c, 2*size+offset, 2.0);
      allocate_align(&d, 2*size+offset, 3.0);
      
      #pragma omp single
      {
	niter = 1;
	nthreads = omp_get_num_threads();
      }
      wtime = triad(a,b,c,d,size,niter);		//warm-up

      while(1)
      {
	#pragma omp barrier
	wtime = triad(a,b,c,d,size,niter);
	#pragma omp barrier
	
	#pragma omp single
	{
	  if(wtime > 0.2)
	  {
	    finish = true;
	  }
	  else
	  {
	    niter *= 2;
	  }
	}
	
	if(finish == true) 
	  break;
      }
      
      deallocate_align(&a);
      deallocate_align(&b);
      deallocate_align(&c);
      deallocate_align(&d);
    }
    mflops = 2.0 * (double) niter * (double) size * nthreads * nthreads / (wtime*1.e6); 
    mbytes = 4.0 * (double) niter * (double) size * nthreads * nthreads * 8.0 / (wtime*1.e6); 

    std::cout << size << " " << size*8.0*4.0/1024. << " " << mflops << " " << mbytes << std::endl;
    
    return 0;
}

double triad(double* __restrict__ a,
       const double* __restrict__ b,
       const double* __restrict__ c,
       const double* __restrict__ d,
       const int array_size,
       const int niter)
{
  CPUTime time;
  double t0,t1;
  
  t0 = time.start();
  for(int i=0; i<niter; ++i)
  {
    #pragma vector aligned
    for(int j=0; j<array_size;++j)
    {
      a[j] = b[j] + c[j] * d[j];
    }
  }  
  t1 = time.stop();
  return (t1-t0);
}
    