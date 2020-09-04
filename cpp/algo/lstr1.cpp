#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
//find the longest repeating sequence

int numsubstrings(std::string str, std::string sub){
  int count = 0;
  size_t found = str.find(sub);
  while ( found != std::string::npos ){
    count++;
    found = str.find(sub, found + 1);
  }
  return count;
}

std::tuple<int, int, std::string> lccp ( std::string s1, std::string s2){
  int n = 0;
  int i = 0;
  int count = 0;
  std::string sub;
  n = (s1.length() < s2.length() ) ? s1.length() : s2.length() ;
  for(i=0;i<n;i++){
    if (s1[i] != s2[i]){
      if ( i == 0 || i == 1 ){
        return std::make_tuple(0,0,std::string(""));
      }
      sub = s1.substr(0,i);
      count = numsubstrings(s1, sub);
      return std::make_tuple(count,sub.length(),sub);
    }
  }
  sub = s1.substr(0,n);
  count = numsubstrings(s1, sub);
  return std::make_tuple(count,sub.length(),sub);
}
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
  int ncount=0, nlength=0;

  std::string scount, slength;
  std::string lrs = "";
  std::string str;
  std::string sub1, sub2;
  std::string rstr;

  //std::cout << "Enter a string : " ;
  //getline(std::cin, str);
  str = "abdfaabdfh";
  str = "acbdfghybdf";
  str = "aabaabaab";
  std::cout << "The string entered is : [" <<str << "]" << std::endl;


  n = str.length();
  for(i=0;i<n;i++){
    for(j=i+1;j<(n-1);j++){
      sub1 = str.substr(i);
      sub2 = str.substr(j);
      auto [tncount, tnlength, rstr] = lccp(sub1, sub2);
      std::cout << sub1 << ":" << sub2 <<":" << rstr << ":"<<tncount <<":"<<tnlength <<std::endl;
      if (tncount == 0 ) continue;
      if ( tncount > ncount ){
        ncount = tncount ;
        std::cout << "******* changed from old string to new string " << scount << ":" << rstr << std::endl;
        scount = rstr;
      }
      if ( tnlength > nlength ){
        nlength = tnlength ;
        slength = rstr;
      }

      //std::cout << sub1 << ":" << sub2 <<":" << rstr << std::endl;
      //std::cout << lrs << ":" << sub1 << ":" << sub2 <<":" << rstr << std::endl;
      //std::cout << str.substr(i, n) << ":" << str.substr(j, n) << std::endl;
    }
  }
  std::cout << "longest substring is " << slength << " with length "<< slength.length() << std::endl;
  std::cout << "most occuring substring is " << scount << " with number of times "<<ncount << std::endl;
}

/*
      The string entered is : [aabaabaab]
      aabaabaab:abaabaab::0:0
      aabaabaab:baabaab::0:0
      aabaabaab:aabaab:aabaab:2:6
      ******* changed from old string to new string :aabaab
      aabaabaab:abaab::0:0
      aabaabaab:baab::0:0
      aabaabaab:aab:aab:3:3
      ******* changed from old string to new string aabaab:aab
      aabaabaab:ab::0:0
      abaabaab:baabaab::0:0
      abaabaab:aabaab::0:0
      abaabaab:abaab:abaab:2:5
      abaabaab:baab::0:0
      abaabaab:aab::0:0
      abaabaab:ab:ab:3:2
      baabaab:aabaab::0:0
      baabaab:abaab::0:0
      baabaab:baab:baab:2:4
      baabaab:aab::0:0
      baabaab:ab::0:0
      aabaab:abaab::0:0
      aabaab:baab::0:0
      aabaab:aab:aab:2:3
      aabaab:ab::0:0
      abaab:baab::0:0
      abaab:aab::0:0
      abaab:ab:ab:2:2
      baab:aab::0:0
      baab:ab::0:0
      aab:ab::0:0
      longest substring is aabaab with length 6
      most occuring substring is aab with number of times 3
*/
