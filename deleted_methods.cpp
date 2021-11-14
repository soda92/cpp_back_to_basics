
#include<iostream>

class S {
   private:
    int _val;

   public:
    S(int val) : _val(val) {}
    S(size_t) = delete;
};

int main() {
    size_t error_val = 1;
    auto obj = S(static_cast<int>(error_val));
    return 0;
}