#include "mdsimul1.h"
#include <cmath>

// function implementations
void material_properties(std::vector<Particle> & balls)
{
  std::mt19937 gen; // random generator: Mersenne-Twister
  gen.seed(1); // control the seed
  std::uniform_real_distribution<> dis(0.5*RAD, 1.0*RAD); // radii between R/2 and R
  
  // set radii randomly
  for(auto & body : balls){
    body.rad=0.8/*dis(gen)*/;
    body.mass=RHO*4*M_PI*body.rad*body.rad*body.rad/3;
  }
}

void initial_conditions(std::vector<Particle> & balls)
{
  // set up uniformly on a 2d grid

  // extract max rad
  double max_rad=-1.0e300;
  for(auto & body : balls){
    if (body.rad >= max_rad) {
      max_rad=body.rad;
    }
  }

  // put on the 2d grid
  const int NX=L/(2*RAD);
  for(int id=0; id<balls.size(); ++id){
    int ix=id%NX; int iy=id%NX;
    balls[id].Rx = max_rad + ix*max_rad;
    balls[id].Ry = 2*max_rad + iy*max_rad;
  }

  // initial velocity could be random, for now everything going up
  balls[0].Vy = +1.2347;
  balls[0].Vx = -1;
  balls[1].Vy = +1.2347;
  balls[1].Vx = -1;
  
}
void compute_force(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    // reset force
    body.Fx = body.Fy = body.Fz = 0.0;

    // add gravitational force
    body.Fy += body.mass*G; // G is already negative

    // add force with bottom wall
    double deltay0 = body.rad - body.Ry;//lower wall
    double deltax0 = body.rad - body.Rx;//left wall
    double deltay1 = body.rad + body.Ry - L;//upper wall
    double deltax1 = body.rad + body.Rx - L;//rigth wall
    if (deltay0 > 0) {
      body.Fy += K*deltay0;
    }
    if (deltax0 > 0) {
      body.Fx += K*deltax0;
    }
    if (deltay1 > 0) {
      body.Fy -= K*deltay1;
    }
    if (deltax1 > 0) {
      body.Fx -= K*deltax1;
    }
        
    // force with other particles? other walls?
    double rela_rdy = balls[1].Ry - balls[0].Ry;
    double rela_rdx = balls[1].Rx - balls[0].Rx;
    double coll_rd = std::sqrt((rela_rdy*rela_rdy)+(rela_rdx*rela_rdx));
    double delta_r = (balls[0].rad+balls[1].rad) - coll_rd;
    if(coll_rd < balls[0].rad + balls[1].rad){
      balls[1].Fx += (K*delta_r)*(rela_rdx/coll_rd);
      balls[1].Fy += (K*delta_r)*(rela_rdy/coll_rd);
      balls[0].Fx -= balls[1].Fx;
      balls[0].Fy -= balls[1].Fy;
      }
  }
  
}

void start_integration(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    body.Vx -= 0.5*body.Fx*DT/body.mass;
    body.Vy -= 0.5*body.Fx*DT/body.mass;
    body.Vz -= 0.5*body.Fx*DT/body.mass;
  }
}

void integrate(std::vector<Particle> & balls)
{
  // use simple leap-frog
  for(auto & body : balls){
    body.Vx += body.Fx*DT/body.mass;
    body.Vy += body.Fy*DT/body.mass;
    body.Vz += body.Fz*DT/body.mass;
    body.Rx += body.Vx*DT;
    body.Ry += body.Vy*DT;
    body.Rz += body.Vz*DT;
  }
}

void print_info(const std::vector<Particle> & balls, const double & time)
{
  // here we print something useful
  // for now is just a test
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  
  std::cout << time
            << "\t" << balls[0].Rx
            << "\t" << balls[0].Ry 
            << "\t" << balls[0].Rz 
            << "\t" << balls[0].Vx 
            << "\t" << balls[0].Vy 
            << "\t" << balls[0].Vz
	    << "\t" << balls[1].Rx
            << "\t" << balls[1].Ry 
            << "\t" << balls[1].Rz 
            << "\t" << balls[1].Vx 
            << "\t" << balls[1].Vy 
            << "\t" << balls[1].Vz
            << "\n";
}
