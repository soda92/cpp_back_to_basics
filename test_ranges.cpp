#include <fmt/core.h>

#include <iostream>
// #include <ranges>
#include <vector>

int main() {
    std::vector<int> ints{0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    // for (int i :
    //      ints | std::view::filter(even) | std::view::transform(square)) {
    //     fmt::print("{} ", i);
    // }
    fmt::print("\n");
    return 0;
}