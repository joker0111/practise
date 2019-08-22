#include <iostream>
#include <utility>
#include <variant>

template <class ...Ts> struct overload : Ts...{using Ts::operator()...; };
template <class ...Ts> overload(Ts...)->overload<Ts...>;

struct Ironman {};
struct Batman {};
struct Spiderman {};

int main() {
    std::variant<Ironman, Batman, Spiderman> jk{Batman()};
    std::visit(overload{
      [](Ironman&) { std::cout << "Ironman visitor" << std::endl; },
      [](Batman&) { std::cout << "Batman visitor" << std::endl; },
      [](Spiderman&) { std::cout << "Spiderman visitor" << std::endl; }
    }, jk);

    // result
    // Batman's operator
}
