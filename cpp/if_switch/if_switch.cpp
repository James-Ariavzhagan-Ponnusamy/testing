//g++ if_switch.cpp -std=c++17 -fconcepts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Disp(std::vector<int> v){
  std::cout << "--------------------------------------------" << std::endl;
  for(auto x:v){
    std::cout<<"x " << x << std::endl;
  }
}

int main()
{
  std::vector<int> v={1,2,3,4,5};
  std::vector<int>::iterator ite;
  Disp(v);


  ite = find(v.begin(), v.end(), 2);
  if ( ite != v.end()) *ite = 3;

  Disp(v);
  if ( auto x=find(v.begin(), v.end(), 6); x != v.end()){
    *x = 12;
  }
  else
  {
    std::cout<<"condition find(12) failed "<<std::endl;
  }

  Disp(v);
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
    --------------------------------------------
    x 1
    x 3
    x 3
    x 4
    x 5
    condition find(12) failed
    --------------------------------------------
    x 1
    x 3
    x 3
    x 4
    x 5

*/
