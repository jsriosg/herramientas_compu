#include <omp.h>
#include <cstdio>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  const int N = 100000;
  int i,j, a[N];
  double mean=0.0;
  double part_mean=0.0;
      
#pragma omp parallel for
  for(i = 0; i < N; i++){
    a[i] = 2*i;
  }
#pragma omp parallel for reduction(+:part_mean)
  for(j=0;j<N;j++){
    part_mean+=a[j];
  }
  mean = part_mean/N;
  std::cout << mean << std::endl;
  return 0;
}
