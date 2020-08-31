#include <iostream>

void disp(int &&i){
  std::cout << "only l value disp  " << i << std::endl;
  int j;
  j = std::move(i);
  std::cout << "i after move only lvalue  " << i << std::endl;
  std::cout << "j after move only lvalue  " << j << std::endl;
}


int main(){
  int i=10;
  disp(12);
  disp(std::move(i));

}
