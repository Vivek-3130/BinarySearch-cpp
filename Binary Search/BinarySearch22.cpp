#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Brute force:O(N*M)
// Function to check if it's possible to split the array such that the largest sum of any subarray is at most 'target'
bool isPossible(const vector<int>& A, int K, int target) {
    int count = 0;
    int currentSum = 0;
    for (int i = 0; i < A.size(); ++i) {
        currentSum += A[i];
        if (currentSum > target) {
            count++;
            currentSum = A[i];
        }
    }
    count++;// Increment count for the last subarray, as next sub array bnana h
    return count <= K;
}

// Function to find the minimum largest sum of split subarrays
// int minLargestSum(const vector<int>& A, int K) {
//     int totalSum = accumulate(A.begin(), A.end(), 0);
//     int maxElement = *max_element(A.begin(), A.end()); //to 
    
//     int low = maxElement; // Minimum possible value for the largest sum
//     int high = totalSum; // Maximum possible value for the largest sum
    
//     for (int i = low; i <= high; ++i) {
//         if (isPossible(A, K, i))
//             return i;
//     }
    
//     return -1; // If no valid result found
// }

// Optimized sol:O(log2M)
int minLargestSum(vector<int> &arr, int k){
    int n = arr.size();
    if(k > n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int mid; 
    // sari book 1 bache ko denge to sum vali value hogi aur low hamara max hoga of the array
    while(low <= high){
        mid = (high + low)/2;
        if(isPossible(arr,k,mid) > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low+1;
}


int main() {
    int N = 5;
    vector<int> A = {1, 2, 3, 4, 5};
    int K = 4;
    
    cout << "Minimized largest sum: " << minLargestSum(A, K) << endl;
    
    return 0;
}
