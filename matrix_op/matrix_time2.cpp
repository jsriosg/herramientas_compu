#include <iostream>

int main(){
  const int M = 7000;
  const int N = 500;

  double *data = nullptr;
  data = new double [M*N];
  
  std::cout << data[((M*N/2) +N/2] << std::endl;

  delete[]data;
  
  return 0;
}
