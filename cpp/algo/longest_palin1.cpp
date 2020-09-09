#include <iostream>
#include <string>
#include <cstring>


bool IsSubPalin(std::string str){
  int i, j;
  int n = 0;
  n = str.length();
  for(i = 0, j=n-1; i <= j ; i++, j--){
    if (str[i] != str[j]){
      return false;
    }
  }
  return true;
}
void long_palin_substr(std::string str){
  int n = 0;
  int i = 0;
  int j = 0;
  int max_length = 1 ;
  int start = 0;

  n = str.length();
  bool table[n][n];

  memset(table, 0, sizeof(table)) ;
  // 1 letter palindrome = max_length = 1
  for(i=0;i<n;i++){
    table[i][i] = true;
  }

 // 2 letter palindrome - repeating chars
  for(i=0;i<n-1;i++){
    if ( str[i] == str[i+1]){
      table[i][i+1] = true ;
      start = i ;
      max_length = 2 ;
    }
  }
  std::cout << "The max length is " << max_length << std::endl;
  //3 to n letter palindrome
  for (int k = 3; k <= n; ++k) {
    for (int i = 0; i < n - k + 1; ++i) {
      j = i + k - 1;
      if (str[i] == str[j] && table[i+1][j-1]){
        std::cout << "i " << i << std::endl;
        std::cout << "j " << j << std::endl;
        std::cout << "max_length " << max_length << std::endl;
        std::cout << "start " << start << std::endl;
        table[i][j] = true;
        if ( k > max_length ){
          max_length = k ;
          start = i ;
        }
      }
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

    The max length is 2
    i 6
    j 9
    max_length 2
    start 10
    i 5
    j 10
    max_length 4
    start 6
    i 4
    j 11
    max_length 6
    start 5
    i 3
    j 12
    max_length 8
    start 4
    max_length 10
    start 3
    The palin substring is     : geeksskeeg

*/
