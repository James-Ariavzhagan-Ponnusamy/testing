//g++ type2.cpp -std=c++17 -fconcepts
#include <iostream>
using namespace std;

int main()
{
  auto x = 1;
  auto y = 2;
  decltype(x+y) z;
  if ( std::is_same<decltype(x), int>::value ){
    std::cout << "TRUE  : std::is_same<decltype(x), int>::value " << std::is_same<decltype(x), int>::value << std::endl;
  }
  else{
    std::cout << "FALSE : std::is_same<decltype(x), int>::value " << std::is_same<decltype(x), int>::value << std::endl;
  }

  if (std::is_same<decltype(x), float>::value){
    std::cout << "TRUE  : std::is_same<decltype(x), float>::value " << std::is_same<decltype(x), float>::value << std::endl;
  }
  else{
    std::cout << "FALSE : std::is_same<decltype(x), float>::value " << std::is_same<decltype(x), float>::value << std::endl;
  }

  if (std::is_same<decltype(z), int>::value){
    std::cout << "TRUE  : std::is_same<decltype(z), int>::value " << std::is_same<decltype(z), int>::value << std::endl;
  }
  else{
    std::cout << "FALSE : std::is_same<decltype(z), int>::value " << std::is_same<decltype(x), int>::value << std::endl;
  }

  return 0;
}

/*
TRUE  : std::is_same<decltype(x), int>::value 1
FALSE : std::is_same<decltype(x), float>::value 0
TRUE  : std::is_same<decltype(z), int>::value 1
*/
