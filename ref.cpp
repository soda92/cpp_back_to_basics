#include <cstdio>

int f(int& i) {
    i = 5;
    return 0;
}

int main() {
    int arr[4]{0};
    f(arr[1]);
    printf("arr[0]: %d arr[1]: %d\n", arr[0], arr[1]);
    return 0;
}
