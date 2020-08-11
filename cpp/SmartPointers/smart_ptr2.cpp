#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SmartPtr{
  T *m_ptr;
public:

  explicit SmartPtr(T *ptr=NULL):m_ptr(ptr){
    cout<<"SmartPtr::Constructor" << endl;
  }

  SmartPtr(const SmartPtr &rhs) {
  cout<<"SmartPtr::Constructor(const SmartPtr)" << endl;
  }

  SmartPtr(SmartPtr &&rhs) noexcept {
    m_ptr = NULL;
    cout << "SmartPtr::Constructor ( move ) " << endl;
    std::swap(this->m_ptr, rhs.m_ptr);
  }

  SmartPtr& operator= (SmartPtr& rhs){
    if(m_ptr != rhs.m_ptr){
      delete m_ptr;
      m_ptr = rhs.m_ptr;
      rhs.m_ptr = NULL;
    }
    return *this;
  }

  ~SmartPtr(){
    cout<<"~SmartPtr()"<<endl;
    if (m_ptr)
      delete m_ptr;
  }
  T* operator->()const{
    return m_ptr;
  }
  T* operator->(){
    return m_ptr;
  }
  T& operator*() const{
    return *m_ptr;
  }
  T& operator*(){
    return *m_ptr;
  }
};

class Test{
  int i;
public:
  Test(int x):i(x){
    cout<<"Test::Constructor(int) " << i << endl;
  }
  void SetData(){
    cout<<"Test::SetData()"<<endl;
  }
  ~Test(){
    cout<<"Test::Destructor " << i <<endl;
  }
  void Display(){
    cout<<"Test::Display " << i << endl;
  }
  Test(){
    cout<<"Test::Constructor "<<endl;
  }
};
int main(){
  vector<SmartPtr<Test>> v;
  for(auto i=0;i<2;i++){
    //SmartPtr<Test> x(new Test(i));
     v.push_back(SmartPtr<Test>(new Test(i)));
  }
}
