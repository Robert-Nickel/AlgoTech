/*  2^3 = 3 * 3 * 3
    2^1 = 2
    2^0 = 1 
    2^-3 = 1 / (2^n) */
#include <iostream>
#include <vector>

using namespace std;

int pow(int a, int n) {
    if(n == 0) { return 1; }
    if(n == 1) { return a; };

    if (n > 0) {
        return a * pow(a, n-1);
    } else {
        return 1 / a * pow(a, n-1);
    }
}

int main() {
    cout << pow(2, 3) << endl;
    return 0;
}