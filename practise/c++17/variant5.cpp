#include <iostream>
#include <utility>
#include <variant>

int main() {
    std::variant<int, double> v;
    v = 123;
    v = "hello"; // error
}
