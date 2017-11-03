#include <iostream>
typedef long double var;
int main(){
  std::cout.precision(25);
  var eps=1;
  var one;
  for(double i=1;i>0;i++){
    eps=eps/2;
    one=1 + eps;
    std::cout<<i<<"  "<<one<<"  "<<eps<<std::endl;
    if(one==1){
      break;
    }
  }
}
