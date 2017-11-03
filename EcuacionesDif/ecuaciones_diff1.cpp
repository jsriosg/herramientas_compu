#include <iostream>
#include <cmath>
#include <vector>

const double d = 0.01;
const double L = 1.479;
const int N = int(L/d)+1;
const int step = 50000;

typedef std::vector<double> Matrix;

void initial_conditions(Matrix &m);
void boundary_conditions(Matrix &m);
void evolve(Matrix &m);
void print(const Matrix &m);

int main(){
  Matrix data(N*N);
  initial_conditions(data);
  boundary_conditions(data);
  for(int i = 0; i < step; ++i){
    evolve(data);
  }
  print(data);
}

void initial_conditions(Matrix &m){
   for(int i = 0; i < N ; i++){
    for(int j = 0; j < N ; j++){
      m[i*N +j] = 1.0;
    }
  }
}

void boundary_conditions(Matrix &m){
  int ii=0, jj=0;

  ii=0;
  for(jj=0;jj<N;++jj)
    m[ii*N+jj]=100.0;
  ii=N-1;
  for(jj=0;jj<N;++jj)
    m[ii*N+jj]=0.0;
  jj=0;
  for(ii=1;ii<N-1;++ii)
    m[ii*N+jj]=0.0;
  jj=N-1;
  for(ii=1;ii<N-1;++ii)
    m[ii*N+jj]=0.0;
  
}

void evolve(Matrix &m){
  for(int i = 0; i < N ; i++){
    for(int j = 0; j < N ; j++){
      if(i==0) continue;
      if(i==N-1) continue;
      if(j==0) continue;
      if(j==N-1) continue;
      m[i*N+j]=(m[(i+1)*N +j]+m[(i-1)*N +j]+m[i*N +(j+1)]+m[i*N +(j-1)])/4.0;
    }
  }
}

void print(const Matrix &m){
   for(int i = 0; i < N ; i++){
    for(int j = 0; j < N ; j++){
      std::cout<< i*d << '\t' << j*d << '\t' << m[i*N +j] << '\n';
    }
    std::cout<< '\n';
  }
}

