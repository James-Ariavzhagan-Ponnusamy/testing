#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

bool IsPalindrome(std::string s){
  int i=0;
  int n = s.length();
  int j;
  for(i=0, j=n-1;i<=j;i++,j--)
  {
    if(s[i] != s[j]) return false;
  }
  return true;
}

int CheckToAdd(std::string s){
  std::string prep;
  std::string app;
  int n, i;
  n = s.length();
  prep = "";
  for(i=n-1;i>=0;i--){
    app = prep + s;
    std::cout << "appended value is " << prep << std::endl ;
    std::cout << "new string value is " << app << std::endl ;

    if (IsPalindrome(app)){
      std::cout << "The string added for making it palindrome is " << prep << std::endl ;
      return prep.length();
    }
    prep = s.substr(i);
    std::reverse(prep.begin(), prep.end());
  }
  return 0;
}
int main(){

  std::string str;
    //std::cout << "Enter a string : " ;
  //getline(std::cin, str);
  str = "abdfaabdfh";
  str = "acbdfghybdf";
  str = "aabaabaab";
  str = "m";
  std::cout << "The string entered is : [" <<str << "]" << std::endl;
  std::cout << "IsPalindrome("<<str<<") is " << IsPalindrome(str) << std::endl ;
  std::cout << CheckToAdd(str) << std::endl;

}

/*
*/
