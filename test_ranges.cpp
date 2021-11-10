#include <fmt/core.h>

#include <range/v3/all.hpp>
#include <vector>

int main() {
    std::vector<int> ints{0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    for (int i : ints | ranges::views::filter(even) |
                     ranges::views::transform(square)) {
        fmt::print("{} ", i);
    }
    fmt::print("\n");
    return 0;
}
