#include <fmt/core.h>

#include <range/v3/all.hpp>

using ranges::for_each;
using ranges::views::iota;

int main() {
    for_each(iota(1, 11), [](auto v) { fmt::print("{} ", v * v); });
    fmt::print("\n");
    return 0;
}
