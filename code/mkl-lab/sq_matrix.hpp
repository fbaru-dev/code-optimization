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
 
#ifndef _SQ_MULTIPLY_HPP
#define _SQ_MULTIPLY_HPP
#include <iostream>
#include "types.hpp"

class sq_matrix
{
	public:
	  int nrows;
	  int ncols;
	  real_type *values;
	  
	  sq_matrix(int nsize) : nrows(nsize), ncols(nsize)
	  {
		values = new real_type[nrows*ncols];
	  };
	  
	  ~sq_matrix()
	  {
		delete [] values;  
	  };
	  
	  void initialize(real_type n)
	  {
		for(int i=0; i<nrows; ++i)
		  for(int j=0; j<ncols; ++j)
		    values[i*ncols + j] = n;
	  };
	  	  
	  void print()
	  {
		for(int i=0; i<nrows; ++i)
		  for(int j=0; j<ncols; ++j)
		    std::cout << "m[" << i << "][" << j << "]= " << values[i*ncols + j] << std::endl;
      }	  	  
};
#endif
