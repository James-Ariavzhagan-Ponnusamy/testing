//g++ tuple.cpp -std=c++17
#include <iostream>
#include <initializer_list>
#include <tuple>
using namespace std;


std::tuple<int, int> Disp(std::initializer_list<int> v){
  int sum,prod;
  sum = 0;
  prod = 1 ;
  for(auto a:v){
    //std::cout<<"a " << a << std::endl;
    sum+=a;
    prod*=a;
    //std::cout<<"sum  " << sum << std::endl;
    //std::cout<<"prod " << prod << std::endl;
  }
  return std::make_tuple(sum, prod);
}

int main()
{
  auto [x, y] = Disp({1,2,3,4,5});
  std::cout << "sum is " << x <<std::endl;
  std::cout << "prod is " << y << std::endl;
  return 0;
}

/*
  sum is 15
  prod is 120
*/
