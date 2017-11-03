#include <iostream>
#include <armadillo>
#include <chrono>

double solvesystem(const int & size);

int main(int argc, char ** argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size
  double sum=0, sum2 =0;
  double time = 0;
  
  for (int rep = 0; rep < N; ++rep){
    srand(rep+1);
    time = solvesystem(M);
    sum += time;
    sum2 += time*time;
  }
  
  double mean = sum/N;
  double sigma = std::sqrt(N*((sum2/N) - mean*mean)/(N-1));
  std::cout<< M*M << "\t" << mean << "\t" << sigma << std::endl;
  
}

double solvesystem(const int & size) 
{
  std::chrono::time_point<std::chrono::system_clock> start,end;
  arma::mat A = arma::randu<arma::mat>(size, size);
  arma::vec b = arma::randu<arma::vec>(size);
  start = std::chrono::system_clock::now();
  arma::mat Q,R;
  arma::lu(Q, R, A);
  arma::vec x = solve(Q, solve(R, b) );
  end = std::chrono::system_clock::now();
  std::cout << x << std::endl;
  std::chrono::duration<double> sec = end - start;
  return sec.count();
}
