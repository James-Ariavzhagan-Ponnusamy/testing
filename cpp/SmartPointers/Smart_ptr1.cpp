#include <iostream>
using namespace std;

template <typename T>
class SmartPtr{
  T *m_ptr;
public:

  explicit SmartPtr(T *ptr=NULL):m_ptr(ptr){}

  SmartPtr& operator= (SmartPtr& rhs){
    if(m_ptr != rhs.m_ptr){
      delete m_ptr;
      m_ptr = rhs.m_ptr;
      rhs.m_ptr = NULL;
    }
    return *this;
  }

  ~SmartPtr(){
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
  Test(int x):i(x){}
  void SetData(){
    cout<<"Test::SetData()"<<endl;
  }
  ~Test(){
    cout<<"Test Destructor of " << i <<endl;
  }
  void Display(){
    cout<<"Test::Display " << i << endl;
  }
  Test(){
    cout<<"Test Constructor "<<endl;
  }
};
int main(){
  SmartPtr<Test> ptr1 (new Test(1));
  SmartPtr<Test> ptr2 (new Test(2));
  ptr1->Display();
  (*ptr1).Display();
  ptr1 = ptr2;
  ptr1->Display();
  (*ptr1).Display();

}
