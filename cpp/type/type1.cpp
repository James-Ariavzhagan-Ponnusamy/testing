//g++ type1.cpp -std=c++17 -fconcepts
#include <iostream>
using namespace std;

int main()
{
    auto x = 4;
    auto y = 3.37;
    auto ptr = &x;
    decltype(x+y) z;
    std::cout << typeid(x).name() << std::endl // i - integer
         << typeid(y).name() << std::endl // d - double
         << typeid(ptr).name() << std::endl // Pi - pointer to integer
         <<typeid(z).name()<<std::endl;  // d - double

    return 0;
}
