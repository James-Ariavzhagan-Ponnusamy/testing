#include <iostream>
#include <string>
#include <cstring>



void long_palin_substr(std::string str){
  int n = str.length();
  int low = 0;
  int high = 0;
  int i=0;
  int max_length = 1 ;
  int start = 0;

  for(i=0;i<n;i++){
    low = i - 1;
    high = i ; // even length palindrome
    while(low >= 0 && high < n && str[low] == str[high]){
      if ( (high - low + 1) > max_length ){
        start = low ;
        max_length = high - low + 1;
      }
      low--;
      high++;
    }
    low = i - 1 ;
    high = i + 1;
    // Odd number
    while(low >= 0 && high < n && str[low] == str[high]){
      if ( (high - low + 1) > max_length ){
        start = low ;
        max_length = high - low + 1;
      }
      low--;
      high++;
    }
  }


  std::cout << "max_length " << max_length << std::endl;
  std::cout << "start " << start << std::endl;
  std::cout << "The palin substring is     : " << str.substr(start, max_length ) << std::endl;
  //std::cout << "The palin substring len is : " << palin.length() << std::endl;
}
int main()
{
  std::string str;

  //str = "forgeeksskeegfor";
  //long_palin_substr(str);
  str = "Geeks";
  str = "forgeeksskeegfor" ;
  long_palin_substr(str);
}

/*
    max_length 10
    start 3
    The palin substring is     : geeksskeeg
*/
