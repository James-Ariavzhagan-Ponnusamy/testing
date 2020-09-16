#include <iostream>
#include <thread>
#include <chrono>   // std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // 10 sec delay
#include <future>

int main(){
  std::packaged_task<int()> task([](){
    std::cout << "before returning 7 " << std::endl;
    std::cout << "std::this_thread::get_id()" << std::this_thread::get_id() << std::endl;
    return 7;
  });

  std::cout << "packaged_task creation  " << std::endl;
  std::future<int> result = task.get_future();
  std::cout << "result assignment" << std::endl;
  std::thread(std::move(task)).detach();
  std::cout << "detached the thread waiting" << std::endl;
  result.wait();
  std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;
  std::cout << "std::this_thread::get_id()" << std::this_thread::get_id() << std::endl;
}

/*
    packaged_task creation
    result assignment
    detached the thread waiting
    before returning 7
    std::this_thread::get_id()140112954267392
    done!
    future result is 7
    std::this_thread::get_id()140112971212672
*/
