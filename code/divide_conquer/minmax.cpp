// Find Minimum and Maximum from a given Array
#include <iostream>
#include <vector>

using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair minMax(vector<int> arr, int idxLeft, int idxRight) {
    struct Pair minmax;

    // if there is 1 element
    if(idxLeft >= idxRight) {
        minmax.min = arr.at(idxLeft);
        minmax.max = arr.at(idxLeft);
        return minmax;
    }

    // if there are 2 elements
    if(idxLeft + 1 >= idxRight) {
        if(arr.at(idxLeft) > arr.at(idxRight)) {
            minmax.max = arr.at(idxLeft);
            minmax.min = arr.at(idxRight);
        } else {
            minmax.max = arr.at(idxRight);
            minmax.min = arr.at(idxLeft);
        }
        return minmax;
    }

    int middle = (idxLeft + idxRight) / 2;
    struct Pair leftMM = minMax(arr, idxLeft, middle);
    struct Pair rightMM = minMax(arr, middle + 1, idxRight);
    
    // compare minimum of 2 parts
    minmax.min = leftMM.min < rightMM.min ? leftMM.min : rightMM.min;
    
    // compare maximum of 2 parts
    minmax.max = leftMM.max > rightMM.max ? leftMM.max : rightMM.max;

    return minmax;
}

int main() {
    vector<int> arr = { 7, -5, -16, -8, 12 };
    
    struct Pair result = minMax(arr, 0, arr.size() - 1);
    cout << "Min: " << result.min << " Max: " << result.max << endl;

    return 0;
}