#include <iostream>
#include <utility>
#include <variant>

struct Ironman {};
struct Batman {};
struct Spiderman {};

int main() {
    std::variant<Ironman, Batman, Spiderman> jk{Batman()};
    std::visit([](auto&& args) {
        using T = std::decay_t<decltype(args)>;
        if constexpr (std::is_same_v<T, Ironman>)
          std::cout << "Ironman visitor" << std::endl;
        else if constexpr (std::is_same_v<T, Batman>)
          std::cout << "Batman visitor" << std::endl;
        else if constexpr (std::is_same_v<T, Spiderman>)
          std::cout << "Spiderman visitor" << std::endl;
    }, jk);

    // https://en.cppreference.com/w/cpp/utility/variant/visit
}
