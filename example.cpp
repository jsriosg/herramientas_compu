#include <iostream>
#include <gsl/gsl_sf_bessel.h>

int main(){
  double x = 0;
  double y;
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  for(int i=1 ; i>0;i++){
    y = gsl_sf_bessel_J0 (x);
    std::cout<<x<<'\t'<<y<<std::endl;
    x+=0.001;
    if(x>=10){
      break;
    }
  }
}
