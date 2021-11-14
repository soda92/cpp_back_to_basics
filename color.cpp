#include <fmt/core.h>
#include <fmt/xchar.h>
#include <fmt/color.h>

int main() {
  fmt::print(fmt::emphasis::bold | fg(fmt::color::red),
           "Elapsed time: {0:.2f} seconds", 1.23);
}
