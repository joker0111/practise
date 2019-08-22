#include <iostream>
#include <utility>
#include <variant>

struct Ironman {};
struct Batman {};
struct Spiderman {};

struct Joker {
    void operator()(Ironman &obj) { std::cout << "Ironman visitor" << std::endl; }
    void operator()(Batman &computer) { std::cout << "Batman visitor" << std::endl; }
    void operator()(Spiderman &computer) { std::cout << "Spiderman visitor" << std::endl; }
};

int main() {
    std::variant<Ironman, Batman, Spiderman> jk{Batman()};
    std::visit(Joker(), jk);

    // https://bitbashing.io/std-visit.html
}
