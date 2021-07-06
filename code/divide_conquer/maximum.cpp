#include <iostream>
#include <vector>

using namespace std;

int max(vector<int> arr, int idx1, int idx2) {
    if(idx1 >= idx2) {
        return arr.at(idx1);
    }
    int middle = (idx1 + idx2) / 2;
    int leftNumber = max(arr, idx1, middle);
    int rightNumber = max(arr, middle+1, idx2);
    return leftNumber  > rightNumber ? leftNumber : rightNumber;
}

int main() {
    vector<int> elements = {4, 20, 7, 100, 8};
    std::cout << max(elements, 0, elements.size() - 1) << std::endl;
}