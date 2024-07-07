#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the kth missing number in the given array
// Bruyte force:O(N)
// int findKthMissing(vector<int> &nums, int k) {
//     int n = nums.size();
//     if(n <= 0) return -1;
//     for(int i =0 ;i< n-1; i++){
//          if(nums[i] <= k){
//             k++;
//         }
//         else break;
//     }
//     return k;
// }

// Optimised Sol:O(logN)
int findKthMissing(vector<int> &nums, int k){
    int n = nums.size() - 1;
    int low = 0;
    int high = n-1;
    int mid;
    int missing;
    while(low <= high){
        mid = (low + high)/2;

        missing = nums[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    // here the missing is 3 what we get and more to find is k - missing that is 2 more
    // arr[high]+k-(Arr[high] - high - 1)
    // at the end if we see in binary search we get low = high + 1;
    return low + k;  //high + 1 + k

}

int main() {
   vector<int> nums = {2,3,4,7,11}; // Example array
   int k = 5; // Example k value

   int kthMissing = findKthMissing(nums, k);
   cout << "The " << k << "th missing number is: " << kthMissing << endl;

   return 0;
}

