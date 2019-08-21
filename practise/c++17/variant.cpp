#include <iostream>
#include <utility>
#include <variant>

struct Ironman {};
struct Batman {};
struct Spiderman {};

struct Joker {
    void operator()(Ironman &obj) { std::cout << "Ironman's operator" << std::endl; }
    void operator()(Batman &computer) { std::cout << "Batman's operator" << std::endl; }
    void operator()(Spiderman &computer) { std::cout << "Spiderman's operator" << std::endl; }
};

int main() {
    std::variant<Ironman, Batman, Spiderman> jk{Batman()};
    std::visit(Joker(), jk);

    // result
    // Batman's operator
}
