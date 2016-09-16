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

//Compile: icc -O0 pipeline.c -o pipe.x

#include "stdio.h"
#define N 1024*1024*1024

typedef unsigned long uint32;
typedef unsigned long long int uint64;
typedef double real;

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

void mutliply_add_01(); void mutliply_add_02(); void mutliply_add_03(); void mutliply_add_04();
void mutliply_add_05(); void mutliply_add_06(); void mutliply_add_07(); void mutliply_add_08();
void mutliply_add_09(); void mutliply_add_10(); void mutliply_add_11(); void mutliply_add_12();
void mutliply_add_13(); void mutliply_add_14(); void mutliply_add_15(); void mutliply_add_16();
void mutliply_add_17(); void mutliply_add_18(); void mutliply_add_19(); void mutliply_add_20();
void mutliply_add_21(); void mutliply_add_22(); void mutliply_add_23(); void mutliply_add_24();
void mutliply_add_25(); void mutliply_add_26(); void mutliply_add_27(); void mutliply_add_28();
void mutliply_add_29(); void mutliply_add_30(); void mutliply_add_31(); void mutliply_add_32();
void mutliply_add_33(); void mutliply_add_34(); void mutliply_add_35(); void mutliply_add_36();
void mutliply_add_37(); void mutliply_add_38(); void mutliply_add_39(); void mutliply_add_40();

int main() 
{
  uint32 iterations = N;
  uint64 before, after, cycles;
  double c_i;
  
  before = startRDTSC();
  mutliply_add_01();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 1, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_02();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 2, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_03();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 3, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_04();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 4, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_05();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 5, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_06();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 6, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_07();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 7, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_08();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 8, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_09();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 9, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_10();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 10, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_11();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 11, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_12();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 12, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_13();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 13, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_14();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 14, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_15();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 15, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_16();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 16, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_17();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 17, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_18();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 18, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_19();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 19, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_20();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 20, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_21();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 21, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_22();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 22, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_23();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 23, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_24();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 24, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_25();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 25, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_26();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 26, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_27();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 27, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_28();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 28, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_29();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 29, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_30();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 30, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_31();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 31, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_32();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 32, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_33();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 33, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_34();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 34, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_35();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 35, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_36();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 36, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_37();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 37, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_38();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 38, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_39();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 39, cycles, c_i);
  
  before = startRDTSC();
  mutliply_add_40();
  after  = stopRDTSC();
  cycles = after-before;
  c_i = (double) cycles/iterations;
  printf("#%d %ld %f\n", 40, cycles, c_i);
  
}
  


void mutliply_add_01()
{
  real d=0.001; int i;
  real c01=0.001;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d;
  }
  printf(" %f", c01);
  printf("\n");
}

void mutliply_add_02()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; 
  }
  printf(" %f", c01); printf(" %f", c02); 
  printf("\n");
}

void mutliply_add_03()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); 
  printf("\n");
}

void mutliply_add_04()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf("\n");
}

void mutliply_add_05()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05);
  printf("\n");
}

void mutliply_add_06()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); 
  printf("\n");
}

void mutliply_add_07()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); 
  printf("\n");
}

void mutliply_add_08()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf("\n");
}

void mutliply_add_09()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); 
  printf("\n");
}

void mutliply_add_10()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); 
  printf("\n");
}

void mutliply_add_11()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); 
  printf("\n");
}

void mutliply_add_12()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf("\n");
}

void mutliply_add_13()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); 
  printf("\n");
}
void mutliply_add_14()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14);
  printf("\n");
}

void mutliply_add_15()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); 
  printf("\n");
}

void mutliply_add_16()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf("\n");
}

void mutliply_add_17()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17);
  printf("\n");
}

void mutliply_add_18()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18);
  printf("\n");
}

void mutliply_add_19()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); 
  printf("\n");
}

void mutliply_add_20()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf("\n");
}

void mutliply_add_21()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); 
  printf("\n");
}

void mutliply_add_22()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); 
  printf("\n");
}

void mutliply_add_23()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); 
  printf("\n");
}

void mutliply_add_24()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf("\n");
}

void mutliply_add_25()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25);
  printf("\n");
}

void mutliply_add_26()
{
    real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); 
  printf("\n");
}

void mutliply_add_27()
{
    real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27);
  printf("\n");
}

void mutliply_add_28()
{
    real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf("\n");
}

void mutliply_add_29()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29);
  printf("\n");
}

void mutliply_add_30()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); 
  printf("\n");
}

void mutliply_add_31()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31);
  printf("\n");
}

void mutliply_add_32()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf("\n");
}

void mutliply_add_33()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33);
  printf("\n");
}

void mutliply_add_34()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); 
  printf("\n");
}

void mutliply_add_35()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); 
  printf("\n");
}

void mutliply_add_36()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; real c36=0.036;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d; c36=c36*c36+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); printf(" %f", c36);
  printf("\n");
}

void mutliply_add_37()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; real c36=0.036;
  real c37=0.037; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d; c36=c36*c36+d;
    c37=c37*c37+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); printf(" %f", c36);
  printf(" %f", c37); 
  printf("\n");
}

void mutliply_add_38()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; real c36=0.036;
  real c37=0.037; real c38=0.038; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d; c36=c36*c36+d;
    c37=c37*c37+d; c38=c38*c38+d; 
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); printf(" %f", c36);
  printf(" %f", c37); printf(" %f", c38); 
  printf("\n");
}

void mutliply_add_39()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; real c36=0.036;
  real c37=0.037; real c38=0.038; real c39=0.039; 
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d; c36=c36*c36+d;
    c37=c37*c37+d; c38=c38*c38+d; c39=c39*c39+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); printf(" %f", c36);
  printf(" %f", c37); printf(" %f", c38); printf(" %f", c39); 
  printf("\n");
}

void mutliply_add_40()
{
  real d=0.001; int i;
  real c01=0.001; real c02=0.002; real c03=0.003; real c04=0.004;
  real c05=0.005; real c06=0.006; real c07=0.007; real c08=0.008;
  real c09=0.009; real c10=0.010; real c11=0.011; real c12=0.012;
  real c13=0.013; real c14=0.014; real c15=0.015; real c16=0.016; 
  real c17=0.017; real c18=0.018; real c19=0.019; real c20=0.020;
  real c21=0.021; real c22=0.022; real c23=0.023; real c24=0.024;
  real c25=0.025; real c26=0.026; real c27=0.027; real c28=0.028;
  real c29=0.029; real c30=0.030; real c31=0.031; real c32=0.032;
  real c33=0.033; real c34=0.034; real c35=0.035; real c36=0.036;
  real c37=0.037; real c38=0.038; real c39=0.039; real c40=0.040;
  for (i=0; i<N; i++) 
  {
    c01=c01*c01+d; c02=c02*c02+d; c03=c03*c03+d; c04=c04*c04+d;
    c05=c05*c05+d; c06=c06*c06+d; c07=c07*c07+d; c08=c08*c08+d;
    c09=c09*c09+d; c10=c10*c10+d; c11=c11*c11+d; c12=c12*c12+d;
    c13=c13*c13+d; c14=c14*c14+d; c15=c15*c15+d; c16=c16*c16+d;
    c17=c17*c17+d; c18=c18*c18+d; c19=c19*c19+d; c20=c20*c20+d;
    c21=c21*c21+d; c22=c22*c22+d; c23=c23*c23+d; c24=c24*c24+d;
    c25=c25*c25+d; c26=c26*c26+d; c27=c27*c27+d; c28=c28*c28+d;
    c29=c29*c29+d; c30=c30*c30+d; c31=c31*c31+d; c32=c32*c32+d;
    c33=c33*c33+d; c34=c34*c34+d; c35=c35*c35+d; c36=c36*c36+d;
    c37=c37*c37+d; c38=c38*c38+d; c39=c39*c39+d; c40=c40*c40+d;
  }
  printf(" %f", c01); printf(" %f", c02); printf(" %f", c03); printf(" %f", c04);
  printf(" %f", c05); printf(" %f", c06); printf(" %f", c07); printf(" %f", c08);
  printf(" %f", c09); printf(" %f", c10); printf(" %f", c11); printf(" %f", c12);
  printf(" %f", c13); printf(" %f", c14); printf(" %f", c15); printf(" %f", c16);
  printf(" %f", c17); printf(" %f", c18); printf(" %f", c19); printf(" %f", c20);
  printf(" %f", c21); printf(" %f", c22); printf(" %f", c23); printf(" %f", c24);
  printf(" %f", c25); printf(" %f", c26); printf(" %f", c27); printf(" %f", c28);
  printf(" %f", c29); printf(" %f", c30); printf(" %f", c31); printf(" %f", c32);
  printf(" %f", c33); printf(" %f", c34); printf(" %f", c35); printf(" %f", c36);
  printf(" %f", c37); printf(" %f", c38); printf(" %f", c39); printf(" %f", c40);
  printf("\n");
}
