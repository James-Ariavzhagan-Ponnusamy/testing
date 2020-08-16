//g++ init_list.cpp -std=c++17 -fconcepts
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;


void Disp(std::initializer_list<int> v, char ch){
  std::cout << "--------------------------------------------" << std::endl;
  for(auto x:v){
    std::cout<<"x " << x << std::endl;
  }
  std::cout <<"---------------------------------------------" <<std::endl;
  std::cout << ch << std::endl;
}

int main()
{
  Disp({1,2,3,4,5}, 'A');
  return 0;
}
/*
  D:\james\cpp\w\types>a
  --------------------------------------------
  x 1
  x 2
  x 3
  x 4
  x 5
  ---------------------------------------------
  A
*/
