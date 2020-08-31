#include <iostream>

void test_lrvalue1(){
  int i = 10;
  int &ref1 = i ;
  const int& ref2 = i ;

  std::cout << "i " << i << std::endl;
  std::cout << "ref1 " << ref1 << std::endl;
  std::cout << "ref2 " << ref2 << std::endl;
}
void test_lrvalue2(){
  int i = 10;
  int &ref1 = i ;
  const int& ref2 = i ;

  std::cout << "i " << i << std::endl;
  std::cout << "ref1 " << ref1 << std::endl;
  // ref2++; - Error lrvalue.cpp:19:3: error: increment of read-only reference 'ref2'
  std::cout << "ref2 " << ref2 << std::endl;
}

void test_lrvalue3(){
  const int& ref1 = 10 ;
  //int& ref1 = 10 ; Not allowed

  std::cout << "ref1 " << ref1 << std::endl;
  // ref2++; - Error lrvalue.cpp:19:3: error: increment of read-only reference 'ref2'
  //std::cout << "ref2 " << ref2 << std::endl;
}


int main(){
  test_lrvalue3();
}
