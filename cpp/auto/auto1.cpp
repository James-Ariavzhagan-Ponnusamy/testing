//g++ auto1.cpp -std=c++17 -fconcepts
#include <iostream>
using namespace std;


auto Add(auto, auto);

auto Add(auto x, auto y){
  std::cout << x + y << std::endl;
  return x + y;
}

int main()
{
  std::cout << "Add " << Add(12,13) << std::endl;
  std::cout << "Add " << Add(12.3,13.2) << std::endl;
  return 0;
}

/*
    D:\james\cpp\w\types>a
    Add 25
    25
    Add 25.5
    25.5
*/
