#include <iostream>
#include <memory>
#include <vector>

class Test{
  int i=0;
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
    std::cout << "void::Get() [ " << this->i << " ]" << std::endl;
  }
  void Set(int i){
    this->i = i;
    std::cout << "void::Set(int i) [ " << this->i << " ]" << std::endl;
  }
};

void foo(std::vector<std::shared_ptr<Test>> ptr){
  std::cout << "Start :: foo" << std::endl;
  for(auto x:ptr){
      x->Get();
      std::cout << "***************************   x.use_count() " << x.use_count() << std::endl;
  }
  std::cout << "End   :: foo" << std::endl;
}

void foo_ref(std::vector<std::shared_ptr<Test>> &ptr){
  std::cout << "Start :: foo" << std::endl;
  for(auto x:ptr){
      x->Get();
      std::cout << "***************************   x.use_count() " << x.use_count() << std::endl;
  }
  std::cout << "End   :: foo" << std::endl;
}

void smpt_test_1(){
  std::cout << "Start :: smpt_test_1" << std::endl;
  {
    auto ptr = std::make_shared<Test>();
    std::cout << "***************************   ptr.use_count() " << ptr.use_count() << std::endl;
    std::vector<std::shared_ptr<Test>> v;
    v.push_back(ptr);
    std::cout << "***************************   ptr.use_count() " << ptr.use_count() << std::endl;

    for(auto x:v){
        x->Get();
        std::cout << "***************************   x.use_count() " << x.use_count() << std::endl;
    }
    foo(v);
    std::cout << "***************************   ptr.use_count() " << ptr.use_count() << std::endl;
    foo_ref(v);
    std::cout << "***************************   ptr.use_count() " << ptr.use_count() << std::endl;

    for(auto x:v){
        x->Get();
        std::cout << "***************************   x.use_count() " << x.use_count() << std::endl;
    }
    std::cout << "***************************   LAST - only vector element and ptr ptr.use_count() " << ptr.use_count() << std::endl;
  }
  std::cout << "End   :: smpt_test_1" << std::endl;
}

int main(){
  smpt_test_1();
}

/*
    Start :: smpt_test_1
    Test::Test()
    ***************************   ptr.use_count() 1
    ***************************   ptr.use_count() 2
    void::Get() [ 0 ]
    ***************************   x.use_count() 3
    Start :: foo
    void::Get() [ 0 ]
    ***************************   x.use_count() 4
    End   :: foo
    ***************************   ptr.use_count() 2
    Start :: foo
    void::Get() [ 0 ]
    ***************************   x.use_count() 3
    End   :: foo
    ***************************   ptr.use_count() 2
    void::Get() [ 0 ]
    ***************************   x.use_count() 3
    ***************************   LAST - only vector element and ptr ptr.use_count() 2
    Test::~Test()
    End   :: smpt_test_1
*/
