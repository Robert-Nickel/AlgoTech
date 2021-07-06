#include <iostream>
#include <vector>

using namespace std;

int maxUnimodal(vector<int> arr, int idx1, int idx2) {
    if(idx1 >= idx2) {
        return arr.at(idx1);
    }
    int middle = (idx1 + idx2) / 2;
    
    // because of unimodality step like binary search can be applied here ;)
    if(arr.at(middle) < arr.at(middle + 1)) {
        return maxUnimodal(arr, middle + 1, idx2);    
    } else {
        return maxUnimodal(arr, 0, middle);
    }
}

int main() {
    vector<int> arr = {1, 3, 4, 5, 7, 8, 10, 12, 13, 14, 10, 9, 6, 2};
    cout << maxUnimodal(arr, 0, arr.size() - 1) << endl;
    return 0;
}