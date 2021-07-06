// find the sum of all integers
#include <iostream>
#include <vector>

using namespace std;

int summeBetraege(vector<int> arr, int idx1, int idx2) {
    if(idx1 >= idx2) {
        return arr.at(idx1) < 0 ? -1 * arr.at(idx1) : arr.at(idx1);
    }

    int middle = (idx1 + idx2) / 2;

    int leftSum = summeBetraege(arr, 0, middle);
    int rightSum = summeBetraege(arr, middle + 1, idx2);
    
    return leftSum + rightSum;
}

int main() {
    vector<int> arr = {1, -20, 3, 200, 40, 5};
    cout << summeBetraege(arr, 0, arr.size() - 1) << endl; 
    return 0;
}

// a = 2
// b = 2
// alpha = logb(a) = 1
// f(O(1)) T(n) -> O(n)