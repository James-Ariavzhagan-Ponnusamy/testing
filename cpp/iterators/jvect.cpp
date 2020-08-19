#include <functional>
#include <iostream>

template <typename TYPE>
class jvect{
  size_t m_Capacity = 0;
  size_t m_Size = 0;
  TYPE  *m_Data = nullptr;

  void ReAlloc(size_t newCapacity){
    std::cout << "jvect ReAlloc " << newCapacity <<std::endl;
    TYPE *ptr = new TYPE[newCapacity];
    for(size_t i = 0 ; i < m_Size ; i++){
      //std::cout << "copying " << i <<std::endl;
      ptr[i] = std::move(m_Data[i]);
    }
    delete []m_Data;
    m_Data = ptr;
    m_Capacity = newCapacity;
  }
public:
  jvect(){
    std::cout << "jvect default constructor " <<std::endl;
    ReAlloc(2);
  }
  //jvect(const data &d){
  //  std::cout << "jvect copy constructor " <<std::endl;
  //}
  ~jvect(){
    delete []m_Data;
    std::cout << "jvect destructor " <<std::endl;
  }

  void push_back(const TYPE &x){
    std::cout << "pushback X " << x << std::endl;
    if (m_Size >= m_Capacity){
      ReAlloc(2 * m_Capacity);
    }
    m_Data[m_Size++] = x;
    std::cout << "added successfully" << std::endl;
  }

  void push_back(TYPE &&x){
    std::cout << "pushback_rvalue X " << x << std::endl;
    if (m_Size >= m_Capacity){
      ReAlloc(2 * m_Capacity);
    }
    m_Data[m_Size++] = std::move(x);
    std::cout << "added successfully" << std::endl;
  }

  template <typename... Args>
  TYPE& emplace_back(Args&&... args){
    std::cout << "emplace_back_rvalue " << std::endl;
    if (m_Size >= m_Capacity){
      ReAlloc(2 * m_Capacity);
    }

    //m_Data[m_Size++] = TYPE(std::forward<Args>(args)...);
    new(&m_Data[m_Size]) TYPE(std::forward<Args>(args)...);
    std::cout << "added successfully" << std::endl;
    return m_Data[m_Size++];
  }
  void PrintData(){
    for(int i=0;i<m_Size;i++){
      std::cout << m_Data[i] << std::endl;
    }
  }

  size_t Size() const {
    return m_Size;
  }

  TYPE& operator[](size_t index){
    return m_Data[index];
  }
  const TYPE& operator[](size_t index) const {
    return m_Data[index];
  }
  typedef TYPE *iterator;
  typedef TYPE *const_iterator;

  iterator begin(){
    return m_Data;
  }
  const_iterator begin() const {
    return m_Data;
  }
  iterator end(){
    return m_Data+m_Size;
  }
  const_iterator end() const {
    return m_Data+m_Size;
  }
};

class Test{
  int n;
public:
  Test(){
    std::cout << "Test::Test()" << std::endl ;
  }
  Test(int m):n(m){
    std::cout << "Test::Test(int)" << std::endl ;
  }
  Test(const Test &d){
    n = d.n;
    std::cout << "Test::Test(const Test &d)" << std::endl ;
  }
  Test(Test &&d) {
    n = std::move(d.n);
    std::cout << "Test::Test(Test &&d)" << std::endl ;
  }
  ~Test(){
    std::cout << "Test::~Test()" << std::endl ;
  }
  operator int(){
    return n;
  }
  operator int() const {
    return n;
  }
  int GetData()const{
    return n;
  }
  Test& operator = (const Test &other){
      std::cout << "copy operator = " << std::endl;
      n = other.n;
      return *this;
  }
  Test& operator = (Test &&other){
    std::cout << "move operator = " << std::endl;
      n = std::move(other.n);
      return *this;
  }
};
template<typename TYPE>
void PrintData(const jvect<TYPE> &v){
  for(auto x:v){
    std::cout << "element  " << x << std::endl;
  }
}
int main() {
  /*
  jvect<std::string> s;
  s.push_back("one");
  s.push_back("two");
  s.push_back("three");
  */
  {
    jvect<Test> s;
    //s.push_back(Test(1));
    //s.push_back(Test(2));
    //s.push_back(Test(3));
    s.emplace_back(1);
    s.emplace_back(2);
    s.emplace_back(3);
    //PrintData(s);
    s.PrintData();  
  }

}
