#include <fmt/core.h>

#include <map>
#include <string>
#include <string_view>


void print_map(const auto &map, const std::string_view key_desc = "key",
               const std::string_view value_desc = "value") {
    for (const auto &[key, value] : map) {
        fmt::print("{}: '{}' {}: '{}'\n", key_desc, key, value_desc, value);
    }
}

int main() {
    std::map<int, std::string> map = {{1, "abc"}, {2, "def"}};
    print_map(map, "key", "value");
    return 0;
}
