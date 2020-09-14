#include <iostream>
#include <thread>
#include <chrono>

int main(){
  std::thread t([](){
    std::cout << "Inside the thread " << std::endl;
  });
  std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // 10 sec delay 
  std::cout << "outside the thread before join " << std::endl;
  t.join();
  std::cout << "outside the thread after join " << std::endl;
}

/*
  Inside the thread
  outside the thread before join
  outside the thread after join

*/
