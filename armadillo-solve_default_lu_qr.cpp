#include <iostream>
#include <armadillo>

void solvesystem(const int & size);

int main(int argc, char** argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size

  for (int step = 0; step < N; ++step) {
    solvesystem(M);
  }  

  return 0;
}

void solvesystem(const int & size) 
{
  // WARNING: ONLY ACTIVATE ONE SOLVE MODE AT A TIME

  arma::mat A = arma::randu<arma::mat>(size, size);
  arma::vec b = arma::randu<arma::vec>(size);
  
  // Default solve 
  arma::vec x = arma::solve(A, b); // normal solve

  // LU
  //arma::mat P,L,U;
  //arma::lu(L, U, P, A);
  //arma::vec x = solve(trimatu(U), solve(trimatl(L), P*b) );

  // QR
  

  // Printing
  //std::cout << x << std::endl;
}
