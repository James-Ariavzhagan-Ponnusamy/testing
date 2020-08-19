#include <functional>
#include <iostream>
template<typename T, size_t N>
class jarray{
  T m_Data[N];
public:
  jarray(){}
  constexpr size_t Size()const {return N;}
  T& operator[](size_t index ){return m_Data[index];}
  const T& operator[](size_t index )const {return m_Data[index];}
  T* Data(){return m_Data;}
  const T* Data()const {return m_Data;}


  typedef T* iterator;
  typedef const T* const_iterator;

  iterator begin(){
    return m_Data;
  }
  const_iterator begin() const{
    return m_Data;
  }
  iterator end(){
    return m_Data+N;
  }
  const_iterator end() const {
    return m_Data+N;
  }
};

int main() {
  jarray<std::string,10> s;
  s[0] = "hello";
  s[1] = "how";
  s[2] = "are";
  s[3] = "you";

  for(auto x:s){
    std::cout << "x " << x << std::endl;
  }
}
