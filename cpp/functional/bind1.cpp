#include <iostream>
#include <functional> // for bind()
using namespace std;

void func(int a, int b, int c)
{
  std::cout<<"A : "<<a<<std::endl;
  std::cout<<"B : "<<b<<std::endl;
  std::cout<<"C : "<<c<<std::endl;
  std::cout << "---------------------------------------------" << std::endl;
}

int main()
{
  using namespace std::placeholders;
    auto fn1 =  bind(func, _1, 2, 3); // second and third parameter are default values

    auto fn2 =  bind(func, 2, _1, 3); // first and third values are default values

    // calling of modified functions
    fn1(10); // 10 2 3
    fn2(10); // 2 10 3

    auto fn3 =  bind(func, _2, 2, _1);
    fn3(12,13); // 13 2 12
    return 0;
}
/*
    A : 10
    B : 2
    C : 3
    ---------------------------------------------
    A : 2
    B : 10
    C : 3
    ---------------------------------------------
    A : 13
    B : 2
    C : 12
    ---------------------------------------------
*/
