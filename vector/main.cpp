#include <iostream>
#include "vector.h"
#include <vector>
#include <climits>


int main(int argc, char** argv) {
  try {
    std::cout << "hello world" << std::endl;
    return 0;
  } catch(const std::exception& e) {
    std::cerr << argv[0] << " error " << e.what() << std::endl;
    return -1;
  }
}
