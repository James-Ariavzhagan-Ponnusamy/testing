#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

//g++ rev_lstr.cpp -std=c++17
//https://www.geeksforgeeks.org/first-substring-whose-reverse-is-a-word-in-the-string/?ref=rp

//find the longest repeating sequence

std::string check_string(std::string s1, std::string s2){
  int n = 0 ;
  int i = 0;

  n = s1.length();
  if ( n < s2.length()) n = s2.length();

  std::cout << "check compare : [" << s1 << "]:[" << s2 << "]" <<std::endl;

  for(i=0;i<n; i++){
    //std::printf("%c-%c\n", s1[i], s2[i]);
    if (s1[i] != s2[i]){
      if (i == 0 || i == 1) return std::string("");

      std::cout << i << " String match found [" << s1.substr(0,i)<<"]"<<std::endl;
      std::exit(0);
    }
  }
  return std::string("");
}

std::string compare (std::string s1, std::string s2){
  std::cout << s1 << ":" << s2 << std::endl;

  for(int i=0;i<s2.length();i++){
    check_string(s1, s2.substr(i));
  }
  return std::string("");
}

int main(){
  std::string str1;
  std::string str2;

  //std::cout << "Enter a string : " ;
  //getline(std::cin, str1);
  str1 = "abdfaabdfh";
  str1 = "acbdfghybdf";
  str1 = "aabaabaab";
  str1 = "mango is sweet when nam en tastes it";
  str1 = "mango is sweet when si en tastes it";
  std::cout << "The string entered is : [" <<str1 << "]" << std::endl;

  str2 = str1;
  std::reverse(str2.begin(), str2.end());
  //str2 = std::string("ma") + str2 ;
  for(int i=0;i<str1.length();i++){
    compare(str1.substr(i), str2);
  }
}

/*
The string entered is : [mango is sweet when si en tastes it]
mango is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [mango is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[is nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[s nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[nehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ehw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[hw teews si ognam]
check compare : [mango is sweet when si en tastes it]:[w teews si ognam]
check compare : [mango is sweet when si en tastes it]:[ teews si ognam]
check compare : [mango is sweet when si en tastes it]:[teews si ognam]
check compare : [mango is sweet when si en tastes it]:[eews si ognam]
check compare : [mango is sweet when si en tastes it]:[ews si ognam]
check compare : [mango is sweet when si en tastes it]:[ws si ognam]
check compare : [mango is sweet when si en tastes it]:[s si ognam]
check compare : [mango is sweet when si en tastes it]:[ si ognam]
check compare : [mango is sweet when si en tastes it]:[si ognam]
check compare : [mango is sweet when si en tastes it]:[i ognam]
check compare : [mango is sweet when si en tastes it]:[ ognam]
check compare : [mango is sweet when si en tastes it]:[ognam]
check compare : [mango is sweet when si en tastes it]:[gnam]
check compare : [mango is sweet when si en tastes it]:[nam]
check compare : [mango is sweet when si en tastes it]:[am]
check compare : [mango is sweet when si en tastes it]:[m]
ango is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [ango is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[is nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[s nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[nehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ehw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[hw teews si ognam]
check compare : [ango is sweet when si en tastes it]:[w teews si ognam]
check compare : [ango is sweet when si en tastes it]:[ teews si ognam]
check compare : [ango is sweet when si en tastes it]:[teews si ognam]
check compare : [ango is sweet when si en tastes it]:[eews si ognam]
check compare : [ango is sweet when si en tastes it]:[ews si ognam]
check compare : [ango is sweet when si en tastes it]:[ws si ognam]
check compare : [ango is sweet when si en tastes it]:[s si ognam]
check compare : [ango is sweet when si en tastes it]:[ si ognam]
check compare : [ango is sweet when si en tastes it]:[si ognam]
check compare : [ango is sweet when si en tastes it]:[i ognam]
check compare : [ango is sweet when si en tastes it]:[ ognam]
check compare : [ango is sweet when si en tastes it]:[ognam]
check compare : [ango is sweet when si en tastes it]:[gnam]
check compare : [ango is sweet when si en tastes it]:[nam]
check compare : [ango is sweet when si en tastes it]:[am]
check compare : [ango is sweet when si en tastes it]:[m]
ngo is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [ngo is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[is nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[s nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[nehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ehw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[hw teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[w teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[teews si ognam]
check compare : [ngo is sweet when si en tastes it]:[eews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ews si ognam]
check compare : [ngo is sweet when si en tastes it]:[ws si ognam]
check compare : [ngo is sweet when si en tastes it]:[s si ognam]
check compare : [ngo is sweet when si en tastes it]:[ si ognam]
check compare : [ngo is sweet when si en tastes it]:[si ognam]
check compare : [ngo is sweet when si en tastes it]:[i ognam]
check compare : [ngo is sweet when si en tastes it]:[ ognam]
check compare : [ngo is sweet when si en tastes it]:[ognam]
check compare : [ngo is sweet when si en tastes it]:[gnam]
check compare : [ngo is sweet when si en tastes it]:[nam]
check compare : [ngo is sweet when si en tastes it]:[am]
check compare : [ngo is sweet when si en tastes it]:[m]
go is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [go is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[is nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[s nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[nehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[ehw teews si ognam]
check compare : [go is sweet when si en tastes it]:[hw teews si ognam]
check compare : [go is sweet when si en tastes it]:[w teews si ognam]
check compare : [go is sweet when si en tastes it]:[ teews si ognam]
check compare : [go is sweet when si en tastes it]:[teews si ognam]
check compare : [go is sweet when si en tastes it]:[eews si ognam]
check compare : [go is sweet when si en tastes it]:[ews si ognam]
check compare : [go is sweet when si en tastes it]:[ws si ognam]
check compare : [go is sweet when si en tastes it]:[s si ognam]
check compare : [go is sweet when si en tastes it]:[ si ognam]
check compare : [go is sweet when si en tastes it]:[si ognam]
check compare : [go is sweet when si en tastes it]:[i ognam]
check compare : [go is sweet when si en tastes it]:[ ognam]
check compare : [go is sweet when si en tastes it]:[ognam]
check compare : [go is sweet when si en tastes it]:[gnam]
check compare : [go is sweet when si en tastes it]:[nam]
check compare : [go is sweet when si en tastes it]:[am]
check compare : [go is sweet when si en tastes it]:[m]
o is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [o is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[is nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[s nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[nehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[ehw teews si ognam]
check compare : [o is sweet when si en tastes it]:[hw teews si ognam]
check compare : [o is sweet when si en tastes it]:[w teews si ognam]
check compare : [o is sweet when si en tastes it]:[ teews si ognam]
check compare : [o is sweet when si en tastes it]:[teews si ognam]
check compare : [o is sweet when si en tastes it]:[eews si ognam]
check compare : [o is sweet when si en tastes it]:[ews si ognam]
check compare : [o is sweet when si en tastes it]:[ws si ognam]
check compare : [o is sweet when si en tastes it]:[s si ognam]
check compare : [o is sweet when si en tastes it]:[ si ognam]
check compare : [o is sweet when si en tastes it]:[si ognam]
check compare : [o is sweet when si en tastes it]:[i ognam]
check compare : [o is sweet when si en tastes it]:[ ognam]
check compare : [o is sweet when si en tastes it]:[ognam]
check compare : [o is sweet when si en tastes it]:[gnam]
check compare : [o is sweet when si en tastes it]:[nam]
check compare : [o is sweet when si en tastes it]:[am]
check compare : [o is sweet when si en tastes it]:[m]
 is sweet when si en tastes it:ti setsat ne is nehw teews si ognam
check compare : [ is sweet when si en tastes it]:[ti setsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[i setsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[ setsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[setsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[etsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[tsat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[sat ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[at ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[t ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[ ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[ne is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[e is nehw teews si ognam]
check compare : [ is sweet when si en tastes it]:[ is nehw teews si ognam]
4 String match found [ is ]
*/
