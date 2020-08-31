#include <iostream>


void disp(int &i){
  std::cout << "disp lvalue " << i << std::endl;
}
void disp(const int &i){
  std::cout << "disp rvalue " << i << std::endl;
}


int main(){
  int i=10;
  disp(i); // lvalue called
  disp(12); // rvalue called
  disp(std::move(i)); // rvalue called

}
