#include <iostream>
#include <thread>
void hello()
{
  std::cout <<
    "Hello world, I'm a thread!"
    << std::endl;
}

int main(int argc, char* argv[])
{
  std::thread thrd(&hello);
  thrd.join();
  return 0;
}