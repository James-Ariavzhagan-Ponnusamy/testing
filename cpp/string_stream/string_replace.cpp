#include <string>
#include <iostream>

//https://stackoverflow.com/questions/5878775/how-to-find-and-replace-string

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}


int main()
{
  std::string s;
  std::cout <<"Enter a string : ";
  std::cin>>s;
  ReplaceStringInPlace(s, "0","91");
  std::cout << s;


}
