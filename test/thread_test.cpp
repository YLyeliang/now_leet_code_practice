// created by yel on 2022/5/31
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

void independentThread() {
  std::cout << "Starting concurrent thread.\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Exiting concurrent thread.\n";
}

void threadCaller() {
  std::cout << "Starting thread caller.\n";
  std::thread t(independentThread);
  t.detach();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Exiting thread caller.\n";
}
namespace test{
std::ofstream dd("test.txt");

void func(){
}

}
int main() {
  threadCaller();
  std::ofstream fout("debug.txt");
  fout << std::to_string(123) << ",";
  fout << '\n';
  fout<<"224";
  fout.close();
}