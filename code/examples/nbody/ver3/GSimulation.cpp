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

#include "GSimulation.hpp"
#include "cpu_time.hpp"

GSimulation :: GSimulation()
{
  std::cout << "===============================" << std::endl;
  std::cout << " Initialize Gravity Simulation" << std::endl;
  set_npart(2000); 
  set_nsteps(500);
  set_tstep(0.1); 
  set_sfreq(50);
}

void GSimulation :: set_number_of_particles(int N)  
{
  set_npart(N);
}

void GSimulation :: set_number_of_steps(int N)  
{
  set_nsteps(N);
}

void GSimulation :: init_pos()  
{
  std::random_device rd;	//random number generator
  std::mt19937 gen(42);  
  std::uniform_int_distribution<int> unif_d(1,R_MAX);
  real_type max = static_cast<real_type> ( R_MAX );
  
  for(int i=0; i<get_npart(); ++i)
  {
    real_type r = static_cast<real_type> ( unif_d(gen) );
    particles->pos_x[i] = -1.0f + 2.0f * r / max; 
    particles->pos_y[i] = -1.0f + 2.0f * r / max;  
    particles->pos_z[i] = -1.0f + 2.0f * r / max; 
    
  }
  
}

void GSimulation :: init_vel()  
{
  std::random_device rd;	//random number generator
  std::mt19937 gen(42);  
  std::uniform_int_distribution<int> unif_d(1,R_MAX);
  real_type max = static_cast<real_type> ( R_MAX );

  for(int i=0; i<get_npart(); ++i)
  {
    real_type r = static_cast<real_type> ( unif_d(gen) );
    particles->vel_x[i] = -1.0e-4f + 2.0f * r / max * 1.0e-4f ; 
    particles->vel_y[i] = -1.0e-4f + 2.0f * r / max * 1.0e-4f ; 
    particles->vel_z[i] = -1.0e-4f + 2.0f * r / max * 1.0e-4f ; 
  }
  
}

void GSimulation :: init_acc() 
{
  for(int i=0; i<get_npart(); ++i)
  {
    particles->acc_x[i] = 0; 
    particles->acc_y[i] = 0;
    particles->acc_z[i] = 0;
  }
}

void GSimulation :: init_mass() 
{
  std::random_device rd;	//random number generator
  std::mt19937 gen(42);  
  std::uniform_int_distribution<int> unif_d(1,R_MAX);
  
  real_type n = static_cast<real_type> (get_npart());
  real_type max = static_cast<real_type> (R_MAX);

  for(int i=0; i<get_npart(); ++i)
  {
    real_type r = static_cast<real_type> ( unif_d(gen) );
    particles->mass[i] = n + n * r / max; 
  }
}

void GSimulation :: start() 
{
  //allocate particles
  particles = new ParticleSoA[get_npart()];
  
  particles->pos_x = new real_type[get_npart()];
  particles->pos_y = new real_type[get_npart()];
  particles->pos_z = new real_type[get_npart()];
  particles->vel_x = new real_type[get_npart()];
  particles->vel_y = new real_type[get_npart()];
  particles->vel_z = new real_type[get_npart()];
  particles->acc_x = new real_type[get_npart()];
  particles->acc_y = new real_type[get_npart()];
  particles->acc_z = new real_type[get_npart()];
  particles->mass  = new real_type[get_npart()]; 

  init_pos();	
  init_vel();
  init_acc();
  init_mass();
  
  print_header();
  
  real_type dt = get_tstep();
  int n = get_npart();
  
  _totTime = 0.; 
  
  const float softeningSquared = 0.001215f*0.001215f;
  const float G = 6.67259e-11;
  
  CPUTime time;
  double ts0 = 0;
  double ts1 = 0;
  int i,j;
  real_type energy;
  
  double gflops = 1e-9 * ( (12. + 18. ) * double( (n*n-1) ) +  double(n) * 19. );
  double av=0.0, dev=0.0;
  int nf = 0;
  
  const double t0 = time.start();
  for (int s=1; s<=get_nsteps(); ++s)
  {   
   ts0 += time.start(); 
   for (i = 0; i < n; i++)// update acceleration
   {
	for (j = 0; j < n; j++)
	{
	  if (i < j || i > j)
	  {
	    real_type distance, dx, dy, dz;
	    real_type distanceSqr = 0.0f;
	    real_type distanceInv = 0.0f;
		  
	    dx = particles->pos_x[j] - particles->pos_x[i];		//1flop
	    dy = particles->pos_y[j] - particles->pos_y[i];		//1flop	
	    dz = particles->pos_z[j] - particles->pos_z[i];		//1flop
	
 	    distanceSqr = sqrtf(dx*dx + dy*dy + dz*dz) + softeningSquared;		//6flops+sqrt
 	    distanceInv = 1.0f / sqrtf(distanceSqr);					//1div+1sqrt

	    particles->acc_x[i] += dx * G * particles->mass[j] * distanceInv * distanceInv * distanceInv;	//6flops
	    particles->acc_y[i] += dy * G * particles->mass[j] * distanceInv * distanceInv * distanceInv;	//6flops
	    particles->acc_z[i] += dz * G * particles->mass[j] * distanceInv * distanceInv * distanceInv;	//6flops

	  }
	}
   }
      energy = 0;

      for (i = 0; i < n; ++i)// update position
      {
		particles->vel_x[i] += particles->acc_x[i] * dt;	//2flops
		particles->vel_y[i] += particles->acc_y[i] * dt;	//2flops
		particles->vel_z[i] += particles->acc_z[i] * dt;	//2flops
	  
		particles->pos_x[i] += particles->vel_x[i] * dt;	//2flops
		particles->pos_y[i] += particles->vel_y[i] * dt;	//2flops
		particles->pos_z[i] += particles->vel_z[i] * dt;	//2flops

		particles->acc_x[i] = 0.;
		particles->acc_y[i] = 0.;
		particles->acc_z[i] = 0.;
	
		energy += particles->mass[i] * (
				  particles->vel_x[i]*particles->vel_x[i] + 
                  particles->vel_y[i]*particles->vel_y[i] +
                  particles->vel_z[i]*particles->vel_z[i]);	//7flops
      }
  
    _kenergy = 0.5 * energy; 
    
    ts1 += time.stop();
    if(!(s%get_sfreq()) ) 
    {
      nf += 1;      
      std::cout << " " 
		<<  std::left << std::setw(8)  << s
		<<  std::left << std::setprecision(5) << std::setw(8)  << s*get_tstep()
		<<  std::left << std::setprecision(5) << std::setw(12) << _kenergy
		<<  std::left << std::setprecision(5) << std::setw(12) << (ts1 - ts0)
		<<  std::left << std::setprecision(5) << std::setw(12) << gflops*get_sfreq()/(ts1 - ts0)
		<<  std::endl;
      if(nf > 2) 
      {
	av  += gflops*get_sfreq()/(ts1 - ts0);
	dev += gflops*get_sfreq()*gflops*get_sfreq()/((ts1-ts0)*(ts1-ts0));
      }
      
      ts0 = 0;
      ts1 = 0;
    }
  
  } //end of the time step loop
  
  const double t1 = time.stop();
  _totTime  = (t1-t0);
  _totFlops = gflops*get_nsteps();
  
  av/=(double)(nf-2);
  dev=sqrt(dev/(double)(nf-2)-av*av);
  
  int nthreads=1;

  std::cout << std::endl;
  std::cout << "# Number Threads     : " << nthreads << std::endl;	   
  std::cout << "# Total Time (s)     : " << _totTime << std::endl;
  std::cout << "# Average Perfomance : " << av << " +- " <<  dev << std::endl;
  std::cout << "===============================" << std::endl;

}


void GSimulation :: print_header()
{
	    
  std::cout << " nPart = " << get_npart()  << "; " 
	    << "nSteps = " << get_nsteps() << "; " 
	    << "dt = "     << get_tstep()  << std::endl;
	    
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << " " 
	    <<  std::left << std::setw(8)  << "s"
	    <<  std::left << std::setw(8)  << "dt"
	    <<  std::left << std::setw(12) << "kenergy"
	    <<  std::left << std::setw(12) << "time (s)"
	    <<  std::left << std::setw(12) << "GFlops"
	    <<  std::endl;
  std::cout << "------------------------------------------------" << std::endl;


}

GSimulation :: ~GSimulation()
{
  delete [] particles->pos_x;
  delete [] particles->pos_y;
  delete [] particles->pos_z;
  delete [] particles->vel_x;
  delete [] particles->vel_y;
  delete [] particles->vel_z;
  delete [] particles->acc_x;
  delete [] particles->acc_y;
  delete [] particles->acc_z;
  delete [] particles->mass;
  delete particles;
}
