//g++ init_list1.cpp -std=c++17 -fconcepts
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

class init_list_test{
  std::vector<int> v;
public:
  init_list_test(std::initializer_list<int> x){
    for(auto a:x){
      cout<<a<<endl;
      v.push_back(a);
    }
  }
  void Disp(){
    std::cout << "--------------------------------------------" << std::endl;
    for(auto x:v){
      std::cout<<"x " << x << std::endl;
    }
    std::cout <<"---------------------------------------------" <<std::endl;
  }
  void TestInit(std::initializer_list<int> vx){
    std::cout << "--------------------------------------------" << std::endl;
    for(auto x:vx){
      std::cout<<"x " << x << std::endl;
    }
    std::cout <<"---------------------------------------------" <<std::endl;
  }
};

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
  init_list_test t({12,13,13,15,35});
  t.Disp();
  t.TestInit({101, 102, 103});
  Disp({1,2,3,4,5}, 'A');
  return 0;
}

/*
    D:\james\cpp\w\types>a
    12
    13
    13
    15
    35
    --------------------------------------------
    x 12
    x 13
    x 13
    x 15
    x 35
    ---------------------------------------------
    --------------------------------------------
    x 101
    x 102
    x 103
    ---------------------------------------------
    --------------------------------------------
    x 1
    x 2
    x 3
    x 4
    x 5
    ---------------------------------------------
    A
*/
