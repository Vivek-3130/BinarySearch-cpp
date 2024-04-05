
#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>
using namespace std;

// Brute force:- O(n^2)
// int smallestDivisor(vector<int> &arr, int limit){
//     for (int divisor = 1;; divisor++) {
//         int division_sum = 0;
//         for (int num : arr) {
//             division_sum += ceil(static_cast<double>(num) / divisor);
//         }
//         if (division_sum <= limit) {
//             return divisor;
//         }
//     }
// }

// Optimised solution:-O(log2(max)*2)
int sumOfDiv(const vector<int>& arr, int divisor) {
    int sum = 0;
    for (int num : arr) {
        // Add the ceiling of num / divisor to the sum 
        sum += ceil(static_cast<double>(num) / divisor);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit){
    int n = arr.size();
    if( n > limit) return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;
    int mid;
    while(low < high){
        mid = (low + high)/2;
        if(sumOfDiv(arr,mid) <= limit){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
     
}


int main() {
  // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
  
    int minDivisor = smallestDivisor(arr,limit);

    if (minDivisor == -1) {
      cout << "No divisor found" << endl;
    } else {
      cout << "Smallest divisor is " << minDivisor << endl;
    }

    return 0;
}