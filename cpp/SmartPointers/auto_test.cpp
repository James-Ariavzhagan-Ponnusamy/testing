#include <iostream>

void auto_test_1(){
  auto ptr = new int;
  *ptr = 11 ;
  std::cout << "*ptr is   " << *ptr << std::endl;
  std::cout << "ptr[0] is " << ptr[0] << std::endl;

  /*
    *ptr is   11
    ptr[0] is 11
  */
}

void auto_test_2(){
  auto ptr = new int[12];
  *ptr = 12 ;
  std::cout << "*ptr is   " << *ptr << std::endl;
  std::cout << "ptr[0] is " << ptr[0] << std::endl;

  /*
    *ptr is   12
    ptr[0] is 12
  */
}

void auto_test_3(){
  auto ptr = new int(13);
  //*ptr = 12 ;
  std::cout << "*ptr is   " << *ptr << std::endl;
  std::cout << "ptr[0] is " << ptr[0] << std::endl;

  /*
    *ptr is   13
    ptr[0] is 13
  */
}


int main(){
  auto_test_1();
  auto_test_2();
  auto_test_3();
}

/*
    *ptr is   11
    ptr[0] is 11
    *ptr is   12
    ptr[0] is 12
    *ptr is   13
    ptr[0] is 13
*/
