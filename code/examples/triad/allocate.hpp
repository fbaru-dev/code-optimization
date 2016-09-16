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
#include "types.hpp"

static void allocate(real_type **ptr, const uint16 size, real_type value)
{
  
  *ptr = new real_type[size];
  #pragma omp parallel for 
  for (uint16 i=0;i<size; i++) {
        (*ptr)[i] = value;
  }
}

static void deallocate(real_type **ptr)
{
  delete [] *ptr;
}

static void allocate_align(real_type **ptr, const uint16 size, real_type value)
{
 //Intel-specific: 16-byte alignment
  posix_memalign((void**) ptr, 64, size*sizeof(double));
  #pragma omp parallel for 
  for (uint16 i=0;i<size; i++) {
        (*ptr)[i] = value;
  }
}

static void deallocate_align(real_type **ptr)
{
  free(*ptr);
}