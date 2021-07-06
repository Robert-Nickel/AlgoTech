#include <iostream>
#include <vector>
using namespace std;

int ggt(int a, int b) {
    return a % b == 0 ? b : ggt(b, a % b);
}

int ggtMultiple(vector<int> arr, int idx1, int idx2) {
    if(idx1 >= idx2 ) {
        return arr.at(idx1); // ggt(a,a) is always a
    }
    int middle = (idx1 + idx2) / 2;
    int ggtLeft =  ggtMultiple(arr, idx1, middle);
    int ggtRight = ggtMultiple(arr, middle + 1, idx2);
    // cout << "ggtLeft: " << ggtLeft << " ggtMultiple(arr, " << idx1 << ", "<< middle << ")"<< endl;
    // cout << "ggtRight: " << ggtRight << " ggtMultiple(arr, " << middle+1 << ", "<< idx2 << ") \n"<< endl;
    int ggtResult = ggt(ggtLeft, ggtRight);
    // cout << "ggtResult: " << ggtResult << "\tggt(" << ggtLeft << ", " << ggtRight << ")\n"<< endl;
    return ggtResult;
}

int main() {
    vector<int> arr = { 30, 36, 24, 48 };
    cout << ggtMultiple(arr, 0, arr.size() - 1) << endl;
}