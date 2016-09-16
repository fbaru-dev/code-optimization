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

// This program measures the latency of memory access using the chain
// of chasing pointers. 
// The array of pointers point to the same buffer and the pointer chain
// is either randomized of strided.
// Once such a memory buffer has been set up, we measure the time of
//
//    void** p = (void**) array[0];
//    while (N-- > 0) {
//       p = (void**) *p;
//    }
//
// The "p = (void**) *p" serialized all the access to the memory.

//To compile: icpc latency.cpp -o lat.x

#include <stdlib.h>
#include <iostream>
#include <math.h>

#define ARRAY_SIZE 1024 		//in Bytes
#define STRIDE_SIZE 8	 		//in Bytes
#define NUM_ITERATIONS 1024*1024*1024

using namespace std;

typedef unsigned long uint32;
typedef unsigned int  uint16;
typedef unsigned long long int uint64;

volatile void* global; 			// to defeat optimizations
//https://www.ccsl.carleton.ca/~jamuir/rdtscpm1.pdf
static __inline__ uint64 startRDTSC (void) {
    unsigned cycles_low, cycles_high;
    asm volatile ("CPUID\n\t"
		  "RDTSC\n\t"
		  "mov %%edx, %0\n\t"
		  "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
		  "%rax", "%rbx", "%rcx", "%rdx");
    return ((uint64) cycles_high << 32) | cycles_low;
}
 
static __inline__ uint64 stopRDTSC (void) {
    unsigned cycles_low, cycles_high;
    asm volatile("RDTSCP\n\t"
		 "mov %%edx, %0\n\t"
		 "mov %%eax, %1\n\t"
		 "CPUID\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax",
		 "%rbx", "%rcx", "%rdx");
    return ((uint64) cycles_high << 32) | cycles_low;
    
}

uint32 measure_overhead_cycles_count()
{
  uint64 before, after, cycles;
  
  before = startRDTSC();
  after = stopRDTSC();
  
  before = startRDTSC();
  after = stopRDTSC();
  
  before = startRDTSC();
  after = stopRDTSC();
  
  cycles = after-before;
  
  return cycles;
  
}

uint32 measure_latency_random(uint16 iterations, uint32 arraysize)
{
  uint32 size = arraysize/sizeof(void*);
  
  void** array = new void*[size];
  uint32*  indices = new uint32[size];
  uint64 before, after, cycles;
  
  uint32 i;

  for (i = 0; i<size; i++ ) 
  {
      uint32 next_addr =  i;
      indices[i] = i;  
  }
  for (uint32 i = 0; i < size-1; ++i) {
    uint32 j = i + lrand48() % (size - i);
    if (i != j) {
	int tmp = indices[i]; indices[i] = indices[j]; indices[j] = tmp;
    }
  }

  // fill memory with pointer references
  for (i = 1; i < size; ++i) 
  {
    array[indices[i-1]] = (void*) &array[indices[i]];
  }
  array[indices[size-1]] = (void*) &array[indices[0]];
   
  delete[] indices;

  // chase the pointers N times
  uint32 N = iterations;
  
  before = startRDTSC();
  void** p = (void**) array[0];
  while (N-- > 0) {
     p = (void**) *p;
  }
  global = *p; 
  after = stopRDTSC();

  cycles = after-before;

  double c_i = (double) cycles/iterations;
   
  delete[] array;
  return c_i;  
}

uint32 measure_latency_strided(uint16 iterations, uint32 arraysize, uint16 stride)
{
  uint32 size = arraysize/sizeof(void*);
  uint16 strideElem = stride/sizeof(void*);
  
  void** array = new void*[size];
  uint32*  indices = new uint32[size];
  uint64 before, after, cycles;
  
  uint32 i;
  
  for (i = 0; i<size; i++ ) 
  {
    uint32 next_addr =  (i*strideElem)%(size-1);
    indices[i] = next_addr;  
  }
  indices[size-1] = size-1;
  
   // fill memory with pointer references
  for (i = 1; i < size; ++i) 
  {
    array[indices[i-1]] = (void*) &array[indices[i]];
  }
  array[indices[size-1]] = (void*) &array[indices[0]];
   
  delete[] indices;
  
  // chase the pointers N times
  uint32 N = iterations;
  
  before = startRDTSC();
  void** p = (void**) array[0];
  while (N-- > 0) {
     p = (void**) *p;
  }
  global = *p; 
  after = stopRDTSC();

  cycles = after-before;

  double c_i = (double) cycles/iterations;
   
  delete[] array;
  return c_i;  
}

int main(int argc, char** argv) 
{
   uint32 iterations = NUM_ITERATIONS;
   uint32 arraysize  = ARRAY_SIZE;  
   uint32 stride     = STRIDE_SIZE;
   uint32 ONE = 1;  
   int maxiter = 32;
//Loop to have strided access to the memory
//    for (int j=1; j<=maxiter; j++ )
//    {
//      arraysize = ARRAY_SIZE*(1<<j);
//      for (int i=1; i<=maxiter ; ++i)
//      {
// 	stride        = STRIDE_SIZE*(1<<i);
// 	if (stride <= arraysize)
// 	{
// 	  uint64 ticks0 = measure_latency_strided(iterations, arraysize, stride); //warm-up cache
// 	  uint64 ticks1 = measure_latency_strided(iterations, arraysize, stride);
// 	  cout << arraysize/1024 << " " << stride << " " << ticks0 << " " << ticks1 << endl;
// 	}
//      }
//    }
//    cout << "##############################" << endl;
//Loop to have random access to the memory   
   for (int j=1; j<=maxiter; j++ )
   {
     arraysize = ARRAY_SIZE*(ONE<<j);
     uint32 ticks0 = measure_latency_random(iterations, arraysize); //warm-up cache
     uint32 ticks1 = measure_latency_random(iterations, arraysize); 
     cout << arraysize/1024  << " " << ticks0 << " " << ticks1 << " " << endl;
    }
   
}
