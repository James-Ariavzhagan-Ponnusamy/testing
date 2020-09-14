#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int g_i1 = 10 ;

void shared_func(int p_number1){
  static std::mutex mx;
  std::unique_lock<std::mutex> lock(mx);
  std::cout << "gi_1 " << g_i1 << ":pnumber1 "<<p_number1 << std::endl;
  g_i1 = p_number1;
  lock.unlock();

  std::cout << "after unlock gi_1 "<<g_i1  << std::endl;
  lock.lock();
  g_i1++;
  std::cout << "after incremented gi_1 "<<g_i1  << std::endl;
  lock.unlock();
}

int main(){
  std::thread t1(shared_func, 2);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //
  std::thread t2(shared_func, 3);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //
  std::thread t3(shared_func, 4);

  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 10 sec delay
  std::cout << "outside the thread before join " << std::endl;
  t1.join();
  t2.join();
  t3.join();
  std::cout << "outside the thread after join " << std::endl;
}

/*
      gi_1 10:pnumber1 2
      after unlock gi_1 2
      after incremented gi_1 3
      gi_1 3:pnumber1 3
      after unlock gi_1 3
      after incremented gi_1 4
      gi_1 4:pnumber1 4
      after unlock gi_1 4
      after incremented gi_1 5
      outside the thread before join
      outside the thread after join
*/
