#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
class jvect{
  T buf[100];
  int nindex = 0;
  typedef T* iterator ;
  typedef const T* const_iterator ;


public:
  jvect() = default ;

  ~jvect(){
    std::cout << "Destructor of vector" << std::endl;
  }

  void push_back(T&& data){
    std::cout << "push_back tmp object " << std::endl;
    buf[nindex++] = std::move(data);
  }
  void push_back(const T& data){
    std::cout << "push_back ref object " << std::endl;
    buf[nindex++] = data;
  }

  iterator begin(){
    return buf;
  }
  const_iterator begin() const{
    return buf;
  }

  iterator end(){
    return buf+nindex;
  }
  const iterator end() const{
    return buf+nindex;
  }
};



int main()
{
  {
    jvect<int> e;
    e.push_back(5);
    e.push_back(4);
    e.push_back(3);
    for(auto &a : e){
      std::cout << a <<std::endl;
    }
    sort(e.begin(), e.end());
    for(auto &a : e){
      std::cout << a <<std::endl;
    }


  }
}


/*
push_back tmp object
push_back tmp object
push_back tmp object
5
4
3
3
4
5
Destructor of vector
*/