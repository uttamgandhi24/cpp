// This program is identical to
// listing2.cpp except that it
// uses Boost.Bind to simplify
// the creation of a thread that
// takes data.

#include <thread>
#include <iostream>
std::mutex io_mutex;
void count(int id)
{
  for (int i = 0; i < 10; ++i)
  {
    std::lock_guard<std::mutex> lock(io_mutex);
    std::cout << id << ": " << i << std::endl;
  }
}
int main(int argc, char* argv[])
{
  std::thread thrd1(std::bind(&count, 1));
  std::thread thrd2(std::bind(&count, 2));
  thrd1.join();
  thrd2.join();
  return 0;
}