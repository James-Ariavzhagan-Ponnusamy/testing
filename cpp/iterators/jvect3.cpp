#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
class jvect{
  T buf[3];
  int nindex = 0;
  typedef T* iterator ;
  typedef const T* const_iterator ;

  /*
  T *buf=nullptr;
  int index=0;
  int capacity=5;
  int size=5;*/
public:
  jvect() = default ;
  //jvect(){
  //  std::cout << " " << std::endl;
  //}
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

class Entity{
  int x=0;
public:
  Entity(){
    std::cout<<"default constructor " << x << std::endl;
  }

  Entity(int x1):x(x1){
    std::cout<<"Constructor " << x << std::endl;
  }

  Entity(const Entity &e){
    x = e.x;
    std::cout<<"Copy Constructor " << x << std::endl;
  }

  Entity(Entity&& e) noexcept {
    x = std::move(e.x);
    e.x = 0;
    std::cout<<"move Constructor " << x << std::endl;
  }

  Entity& operator = (const Entity &other){
    if ( this != &other)
    {
      x = other.x;
    }
    std::cout<<"operator = " << x  << std::endl;
    return *this;
  }

  Entity& operator = (Entity &&other) noexcept {
    if ( this != &other)
    {
      x = std::move(other.x);
      other.x = -1;
    }
    std::cout<<"move operator = " << x  << std::endl;
    return *this;
  }

  void Print(){
    std::cout<<"print " << x << std::endl;
  }
  ~Entity(){
    std::cout<<"Destructor  " << x  << std::endl;
  }
  friend std::ostream& operator << ( std::ostream &out, const Entity &s);
};

std::ostream& operator << ( std::ostream &out, const Entity &s){
  out<<s.x ;
  return out;
}

void test1()
{
  std::vector<Entity> v;
  v.push_back(Entity(1));
  v.push_back(Entity(2));
}

int main()
{
  {
    jvect<Entity> e;
    Entity x(1);
    Entity y(2);
    e.push_back(x);
    e.push_back(y);
    e.push_back(Entity(3));
    for(auto &a : e){
      std::cout << a <<std::endl;
    }
  }
}
