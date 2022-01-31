#include <fmt/core.h>

void f(auto a) { fmt::print("{}\n", a); }

int main() {
    auto i = 5;
    auto f2 = [&]() { f(i); };
    f2();
}
