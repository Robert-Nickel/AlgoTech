#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Returns sum of maxium subarray sum.
int MaxSubArraySum(int arr[], int n) {
	if(n==1) {return arr[0]; } // base case 
	int mid = n/2;
    
    // recurse over left side
    int left_MSS = MaxSubArraySum(arr, mid);
    
    // we are passing address of mth element of arr as start address and number of elements
    int right_MSS = MaxSubArraySum(arr+mid, n-mid); 
    
    int leftsum = INT_MIN; 
    int rightsum = INT_MIN;
    int sum = 0; // take care of intermediate sums

    // find right-side value value
    for(int i = mid; i < n; i++) {
        sum += arr[i];
        rightsum = max(rightsum, sum);
    }

    // find left-side sum value
    sum = 0;
    for(int i = (mid-1); i >= 0; i--) {
        sum += arr[i];
        leftsum = max(leftsum, sum);
    }

    // result will be max of left or right side
    int result = max(left_MSS, right_MSS);
    // compare that with the case if subarray crosses midpoint
    return max(result, leftsum+rightsum);
}


int main() {
    int a[10] = {-5, 10, 1, -30, 2, 2, 4, 8, -4, 5}; 
    cout << MaxSubArraySum(a, 10) << endl;
    return 0;
}
