#include <iostream>

void binary(int n) {
    if(n < 1) return;
    binary(n/2);
    std::cout << n % 2 << " ";
}

int main() {
    binary(7);
    return 0;
}
