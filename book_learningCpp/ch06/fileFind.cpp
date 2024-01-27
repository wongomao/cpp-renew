#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "The name of the program is: " << argv[0] << std::endl;
  std::cout << "The number of arguments is: " << argc << std::endl;
  for (int i = 1; i < argc; ++i) {
    std::cout << "Argument " << i << " is: " << argv[i] << std::endl;
  }
  return 0;
}
