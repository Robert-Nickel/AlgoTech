/* Der ggT von zwei positiven ganzen Zahlen a und b ist:
   - b, wenn bei der Division von a durch b kein Divisionsrest 
   - sonst ggT(b, a % b)  */
#include <iostream>

int ggt(int a, int b) {
    return a % b == 0 ? b : ggt(b, a % b);
}

int main() {
    int a = 10;
    int b = 5;
    std::cout << ggt(a, b) << std::endl;
}