#include <cmath>
#include <iostream>
#include <cstdlib>
typedef int hello;
int main(){
  hello under =1;
  hello over = 1;
  bool u = false;
  bool o = false;
  for(double i=1;i>0;i++){
    under -= 100;
    over += 100;
    if(std::isinf(over)==true && o==false){
      std::cout<<"Overflow was in "<<i<<std::endl;
      o = true;
    }
    if(std::isinf(-under)==true && u==false){
      std::cout<<"Underflow was in "<<i<<std::endl;
      u = true;
    }
    if(o==true && u==true){
      break;
    }
  }
}
