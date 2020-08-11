#include <iostream>
#include <array>
using namespace std;


void test_lambda1(){
  auto x = []{
    cout<<"[]{} no capture, no parameter and no return type" << endl;
  };
  x();
}

void Display(std::array<std::string, 2> t){
  for(auto x:t){
    cout <<"X " << x << endl;
  }
}
int main(){
  std::array<std::string, 2> a3 = { std::string("a"), "b" };
  Display(a3);
  test_lambda1();
  return 0;
}
