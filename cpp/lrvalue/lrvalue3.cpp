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

class Entity{
  String m_Name;
public:
  Entity(const String &param) : m_Name(param){
    std::cout << "normal constructor of Entity m_Name : " << m_Name <<std::endl;
  }
  Entity(String &&param) : m_Name(std::move(param)){
    std::cout << "r value constructor of entity called  : " << m_Name <<std::endl;
  }

  void Print(){
    m_Name.Print();
  }
};
int main(){

  Entity e(String("one"));
  e.Print();
  //String s("hello");
  //std::cout << s << std::endl;
}


/*
    g++ lrvalue3.cpp -std=c++17
    Constructor - 4243757 one
    copying the data
    Constructor - 15341248 one
    1- Move Constructor - 15341248 one
    move constructor
    2 - Move Constructor - 15341248 one
    r value constructor of entity called  : one

    NULL
    $$$$$$$$$$$$$$$$ print  - 15341248 one
    ********** Destructor  - 15341248 one

*/
