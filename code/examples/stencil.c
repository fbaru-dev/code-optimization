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

//Compile: icc -qopenmp -O0 stencil.c -o stencil-0.x
//	   icc -qopenmp -O3 -xAVX stencil.c -o stencil-1.x
//run: OMP_NUM_THREADS=1 ./stencil-0.x
//     OMP_NUM_THREADS=1 ./stebcil-1.x
//compare results			

#include <math.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int n = 500;
    float x[n][n][n];
    float y[n][n][n];
    float b = 2.0;
    int i,j,k;
    double fTimeStart, fTimeEnd;

    for(i=0; i<n; i++)
      for(j=0; j<n; j++)
	for(k=0; k<n; k++) {
	  x[i][j][k] = 1.0f;
	  y[i][j][k] = 0.0f;
	}

	
    fTimeStart = omp_get_wtime();  
#pragma omp parallel for collapse(3)
    for(i=1; i<n-1; i++)
     for(j=1; j<n-1; j++)
      for(k=1; k<n-1; k++) {
	 y[i][j][k] = b * ( x[i-1][j][k] + x[i+1][j][k] + x[i][j-1][k] +
			    x[i][j+1][k] + x[i][j][k-1] + x[i][j][k+1]	);
      }

    fTimeEnd = omp_get_wtime();	
   
    printf("  wall clock time     = %.2f\n", fTimeEnd - fTimeStart);

    return 0;
}
