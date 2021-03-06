#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 512

void matrix(float ***a){
  int i,j;
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }
}
void full_matrix1(float ***a){
  int i,j,k;
  for (k=0; k<n; ++k)
    for (j=0; j<n; ++j)
      for (i=0; i<n; ++i)
        a[i][j][k] = 1.0;
}
void full_matrix2(float ***a){
  int i,j,k;
  for(i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      for (k=0; k<n; ++k)
        a[i][j][k] = 2.3;
}

void free_matrix(float ***a){
  int i,j;
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      free(a[i][j]);
    free(a[i]);
  }
  free(a);
}

int main(){
  float ***a =  malloc(n*sizeof(float **));
  clock_t cputime1, cputime2;
  
   // Allocating memory for array/matrix
  
  matrix(a);
  cputime1 = clock();
  full_matrix1(a);
  cputime2=clock() - cputime1;
  printf("Time with fast index inside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  full_matrix2(a);
  cputime2=clock() - cputime1;
  printf("Time with fast index outside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  // Clearing memory
  free_matrix(a);

  return 0;
}
