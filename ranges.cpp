#include <fmt/core.h>

#include <range/v3/all.hpp>

using namespace ranges;

int main() {
    for_each(views::iota(1, 11), [](auto v) { fmt::print("{} ", v * v); });
    fmt::print("\n");
    return 0;
}
