#include <iostream>
#include <memory>

class Test{
public:
  Test(){
    std::cout << "Test::Test()" << std::endl;
  }
  ~Test(){
    std::cout << "Test::~Test()" << std::endl;
  }
  Test(const Test &t){
    std::cout << "Test::Test(const Test &t)" << std::endl;
  }
  void Get(){
    std::cout << "void::Get()" << std::endl;
  }
  void Set(int i){
    std::cout << "void::Set(int i) [ " << i << " ]" << std::endl;
  }
};

void foo(std::shared_ptr<Test> ptr){
  std::cout << "Start :: foo" << std::endl;
  ptr->Get();
  std::cout << "ptr.use_count() " << ptr.use_count() << std::endl;
  std::cout << "End   :: foo" << std::endl;
}

void smpt_test_1(){
  std::cout << "Start :: smpt_test_1" << std::endl;
  {
    auto ptr = std::make_shared<Test>();
    std::cout << "ptr.use_count() " << ptr.use_count() << std::endl;
    ptr->Get();
    ptr->Set(12);
    foo(ptr);
  }
  std::cout << "End   :: smpt_test_1" << std::endl;
}

int main(){
  smpt_test_1();
}

/*
    Start :: smpt_test_1
    Test::Test()
    ptr.use_count() 1
    void::Get()
    void::Set(int i) [ 12 ]
    Start :: foo
    void::Get()
    ptr.use_count() 2
    End   :: foo
    Test::~Test()
    End   :: smpt_test_1
*/
