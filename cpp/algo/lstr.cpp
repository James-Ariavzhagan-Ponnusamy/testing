#include <iostream>
#include <string>
#include <sstream>

//find the longest repeating sequence

std::string lcp ( std::string s1, std::string s2){
  int n ;
  int i ;
  n = s1.length();
  if ( n > s2.length()) n = s2.length();

  for(i=0;i<n;i++){
    if (s1[i] != s2[i]){
      std::cout << s1 << ":" <<s2 << ":" <<s1.substr(0,i) << std::endl;
      return s1.substr(0, i);
    }
  }
  std::cout << s1 << ":" <<s2 << ":" <<s1.substr(0,n) << std::endl;
  return s1.substr(0,n);
}

int main(){
  int i, j, n;
  std::string lrs = "";
  std::string str;
  std::string sub1, sub2;
  std::string rstr;

  //std::cout << "Enter a string : " ;
  //getline(std::cin, str);
  str = "abdfaabdfh";
  str = "acbdfghybdf";
  std::cout << "The string entered is : [" <<str << "]" << std::endl;


  n = str.length();
  for(i=0;i<n;i++){
    for(j=i+1;j<(n-1);j++){
      sub1 = str.substr(i);
      sub2 = str.substr(j);
      rstr = lcp(sub1, sub2);
      //std::cout << sub1 << ":" << sub2 <<":" << rstr << std::endl;
      if (rstr.length() > lrs.length()){
        lrs = rstr;
      }
      //std::cout << lrs << ":" << sub1 << ":" << sub2 <<":" << rstr << std::endl;
      //std::cout << str.substr(i, n) << ":" << str.substr(j, n) << std::endl;
    }
  }
  std::cout << lrs << std::endl;
}
