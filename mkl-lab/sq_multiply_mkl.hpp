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
 
#ifndef _SQ_MATRIX_HPP
#define _SQ_MATRIX_HPP

#include <iostream>
#include "types.hpp"
#include "mkl.h"

static void sq_multiply_0(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);
static void sq_multiply_1(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);
static void sq_multiply_2(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);
static void sq_multiply_3(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);
static void sq_multiply_4(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);
static void sq_multiply_5(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);

static void sq_dgemm(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a);

static void sq_multiply_0(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int i=0; i<nrows_a; ++i)
	  for(int j=0; j<ncols_b; ++j)
	    for(int k=0; k<ncols_a; ++k)
	      c[i*ncols_b + j] += a[i*ncols_a + k] * b[k*ncols_b + j];
}

static void sq_multiply_1(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int i=0; i<nrows_a; ++i)		//ijk
	  for(int j=0; j<ncols_b; ++j)
	  {
		real_type sum = 0.0;
	    for(int k=0; k<ncols_a; ++k)
	      sum += a[i*ncols_a + k] * b[k*ncols_b + j];
	    c[i*ncols_b + j]= sum;
	  }
}

static void sq_multiply_2(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int k=0; k<ncols_a; ++k)		//kij
	  for(int i=0; i<nrows_a; ++i)
	  {
		real_type r = a[i*ncols_a + k];
	    for(int j=0; j<ncols_b; ++j)
	      c[i*ncols_b + j] += r * b[k*ncols_b + j];
	  }
}

static void sq_multiply_3(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int i=0; i<nrows_a; ++i)		//ikj
	  for(int k=0; k<ncols_a; ++k)
	  {
		real_type r = a[i*ncols_a + k];
	    for(int j=0; j<ncols_b; ++j)
	      c[i*ncols_b + j] += r * b[k*ncols_b + j];
	  }
}

static void sq_multiply_4(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int j=0; j<ncols_b; ++j)		//jki
	  for(int k=0; k<ncols_a; ++k)
	  {
		real_type r = b[k*ncols_b + j];
	    for(int i=0; i<nrows_a; ++i)
	      c[i*ncols_b + j] += a[i*ncols_a + k] * r;
	  }
}

static void sq_multiply_5(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
	for(int k=0; k<ncols_a; ++k)		//kij
	  for(int i=0; i<nrows_a; ++i)
	  {
		real_type r = a[i*ncols_a + k];
	    for(int j=0; j<ncols_b; ++j)
	      c[i*ncols_b + j] += r * b[k*ncols_b + j];
	  }
}

static void sq_dgemm(real_type* c, real_type* a, real_type* b, const int nrows_a, const int ncols_b, const int ncols_a)
{
     cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, nrows_a, ncols_b, ncols_a, 1., a, ncols_a, 
          b, ncols_b, 0., c, ncols_a);
}


#endif
