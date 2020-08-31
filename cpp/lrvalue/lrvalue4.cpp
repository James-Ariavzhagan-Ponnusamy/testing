#include <iostream>
#include <cstring>

class String{
  size_t m_nSize;
  char * m_pszData;
public:
  String() = default;
  String(const char *pszString){
    printf("Constructor - %u %s\n", pszString, pszString);
    std::cout<<"copying the data "<<std::endl;
    m_nSize = strlen(pszString) + 1 ;
    m_pszData = new char[m_nSize];
    memcpy(m_pszData, pszString, m_nSize);
    printf("Constructor - %u %s\n", m_pszData, m_pszData);
  }
  String(const String &str){
    printf("Copy Constructor - %u %s \n", str.m_pszData, str.m_pszData);
    std::cout<<"copy constructor"<<std::endl;
    m_nSize = str.m_nSize;
    m_pszData = new char[m_nSize];
    memcpy(m_pszData, str.m_pszData, m_nSize);
    printf("Copy Constructor - %u %s\n", m_pszData, m_pszData);
  }

  String(String&& str) noexcept {
    printf("1- Move Constructor - %u %s \n", str.m_pszData, str.m_pszData);
    std::cout<<"move constructor"<<std::endl;
    m_nSize = std::move(str.m_nSize);
    m_pszData = std::move(str.m_pszData);
    str.m_pszData = nullptr;
    printf("2 - Move Constructor - %u %s\n", m_pszData, m_pszData);
  }

  String& operator = (const String &other){
    printf("Assignment operator - %u %s \n", other.m_pszData, other.m_pszData);
    std::cout<<"copy constructor"<<std::endl;
    m_nSize = other.m_nSize;
    m_pszData = new char[m_nSize];
    memcpy(m_pszData, other.m_pszData, m_nSize);
    printf("Assignment operator - %u %s\n", m_pszData, m_pszData);
    return *this;
  }
  String& operator = (String &&other){
    printf("Assignment operator - %u %s \n", other.m_pszData, other.m_pszData);
    std::cout<<"copy constructor"<<std::endl;
    m_nSize = other.m_nSize;
    m_pszData = std::move(other.m_pszData);
    other.m_pszData = nullptr;
    //memcpy(m_pszData, other.m_pszData, m_nSize);
    printf("Assignment operator - %u %s\n", m_pszData, m_pszData);
    return *this;
  }
  void Print(){
    printf("$$$$$$$$$$$$$$$$ print  - %u %s\n", m_pszData, m_pszData);
  }
  ~String(){
    if (m_pszData != nullptr )
    {
      printf("********** Destructor  - %u %s\n", m_pszData, m_pszData);
      delete m_pszData;
    }
    else
      printf("NULL\n");

  }
  friend std::ostream& operator << ( std::ostream &out, const String &s);
};

std::ostream& operator << ( std::ostream &out, const String &s){
  out<<s.m_pszData<<std::endl;
  return out;
}

int main(){
  String s = "string s";
  String dst = std::move(s) ;
  s = std::move(dst);

  std::cout << s<< std::endl;
}


/*
    g++ lrvalue4.cpp -std=c++17
    Constructor - 4243754 string s
    copying the data
    Constructor - 15603392 string s
    1- Move Constructor - 15603392 string s
    move constructor
    2 - Move Constructor - 15603392 string s
    Assignment operator - 15603392 string s
    copy constructor
    Assignment operator - 15603392 string s
    string s

    NULL
    ********** Destructor  - 15603392 string s
*/
