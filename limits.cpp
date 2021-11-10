#include <iostream>
#include <limits>

double factorial(int n) {
    double ret = 1;
    bool int_fl = false;
    for (int i = 1; i <= n; i++) {
        ret *= i;
        if (ret > std::numeric_limits<int>::max() && !int_fl) {
            std::cout << "max factorial that int can store: " << i - 1 << "\n";
            int_fl = true;
        }
        if (ret > std::numeric_limits<double>::max()) {
            std::cout << "max factorial that double can store: " << i - 1
                      << "\n";
            break;
        }
    }
    return ret;
}

int main() {
    int imax = std::numeric_limits<int>::max();
    std::cout << imax << '\n';
    double dmax = std::numeric_limits<double>::max();
    std::cout << dmax << '\n';
    std::cout << factorial(1000) << '\n';
    return 0;
}