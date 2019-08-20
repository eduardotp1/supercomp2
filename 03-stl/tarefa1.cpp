#include <iostream>
#include <boost/unique_ptr.hpp>

int main() {
  boost::unique_ptr<int> ptr = unique_ptr<int>(new int(0));
  for(int f=0;f<1024*1024*1024;f++) {
    *ptr = unique_ptr<int>(new int(f));
  }
  std::cout << "valor final = " << *ptr << std::endl;
}
