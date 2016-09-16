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

#include "sq_matrix.hpp"
#include "sq_multiply.hpp"
#include "cpu_time.hpp"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <omp.h>

int main(int argc, char** argv) 
{
  CPUTime time;	
  double gflops, av, dev;
  double t0 = 0.;
  double t1 = 0.;
  double tt = 0.;
  sq_matrix *a;
  sq_matrix *b; 
  sq_matrix *c;
  int N = 512;		    //matrix size
  
  int nsteps = 10;
  
  if(argc>1)
  {
    N=atoi(argv[1]);
  }
  
  a = new sq_matrix(N);
  b = new sq_matrix(N);
  c = new sq_matrix(N);
  
  a->initialize(1.0);
  b->initialize(2.0);
  
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << " " 
	    <<  std::left << std::setw(8)  << "s"
	    <<  std::left << std::setw(12) << "c[.][.]"
	    <<  std::left << std::setw(12) << "time (s)"
	    <<  std::left << std::setw(12) << "GFlops"
	    <<  std::endl;
  std::cout << "------------------------------------------------" << std::endl;
  
  gflops =  1e-9 * 2.0 * double(N) * double(N) * double(N);
  tt = time.start();
  for (int s=1; s<=nsteps; ++s)
  {  
	c->initialize(0.0);   
    t0 = time.start();
      sq_multiply_0(c->values, a->values, b->values, a->nrows, b->ncols, a-> ncols);
    t1 = time.stop();
    
    std::cout << " " 
		<<  std::left << std::setw(8)  << s
		<<  std::left << std::setprecision(5) << std::setw(12)  << c->values[(N/2) * N + N/2]
		<<  std::left << std::setprecision(5) << std::setw(12) << (t1 - t0)
		<<  std::left << std::setprecision(5) << std::setw(12) << gflops/(t1 - t0)
		<<  std::endl;
	if(s>2)
	{
		av  += gflops/(t1 - t0);
		dev += gflops*gflops/((t1-t0)*(t1-t0));
	}	
	
  }
  tt = time.stop() - tt;
  av/=(double)(nsteps-2);
  dev=sqrt(dev/(double)(nsteps-2)-av*av);
  
  int nthreads=1;
  #pragma omp parallel
  nthreads=omp_get_num_threads();  std::cout << std::endl;
  
  std::cout << "# Number Threads     : " << nthreads << std::endl;	   
  std::cout << "# Total Time (s)     : " << tt << std::endl;
  std::cout << "# Average Perfomance : " << av << " +- " <<  dev << std::endl;
  std::cout << "===============================" << std::endl;
  
  delete a;
  delete b;
  delete c;
  
  return 0;
}
