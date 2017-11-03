#include <iostream>

int main(){
  const int M = 7000;
  const int N = 500;

  double **data = nullptr;
  data = new double *[M];
  for(int i = 0 ; i < M ; ++i){
    data[i]=new double [N];
  }

  std::cout << data[M/2][N/2] << std::endl;

  for(int i = 0 ; i < M ; ++i){
   delete[] data[i];
  }
  delete[]data;
  
  return 0;
}
