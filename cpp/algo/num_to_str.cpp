#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/

std::string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
std::string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };


std::string num2words(int n, std::string s)
{
  std::string str = "";
  if ( !n ) return str;

  //std::cout << "************ " << n << std::endl;
  if (n > 19) // 23
  {
    str += ten [n / 10] ; // 2
    str += one [n % 10] ; // 3
  }
  else
  { // 18
    str += one[n];
  }
  if ( n )
  {
    str += s ;
  }
  //std::cout << str << std::endl ;
  return str;
}
std::string convertToWords(long n)
{
  std::string out;
  out += num2words((n / 10000000), "crore ");
  out += num2words(((n / 100000)%100), "lakhs "); // 2 digit

  out += num2words(((n / 1000)%100), "thousand "); // 2 digit
  out += num2words(((n / 100)%10), "hundred "); // 1 digit

  if (n > 100 && n % 100)
        out += "and ";
  out += num2words((n % 100), "");
  return out;

}
int main(){
  auto result = convertToWords(42342);
  std::cout <<"Result :" << result  << std::endl;
}
/*
*/
