#include <iostream>
#include <utility>
#include <variant>

int main() {
  std::variant<int, double> v = 10;
  std::cout << v.index() << std::endl;

  v = 3.14;
  std::cout << v.index() << std::endl;
}
