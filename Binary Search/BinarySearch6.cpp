#include <iostream>
#include <vector>
using namespace std;

// pair<int, int> first_and_last_occurrence(vector<int>& nums, int target) {
//     int first_occurrence = -1, last_occurrence = -1;

//     // Finding the first occurrence
//     for (int i = 0; i < nums.size(); ++i) {
//         if (nums[i] == target) {
//             first_occurrence = i;
//             break;
//         }
//     }

//     // Finding the last occurrence
//     for (int i = nums.size() - 1; i >= 0; --i) {
//         if (nums[i] == target) {
//             last_occurrence = i;
//             break;
//         }
//     }

//     return make_pair(first_occurrence, last_occurrence);
// }

// int main() {
//     vector<int> nums = {1, 2, 2, 2, 3, 4, 5, 5, 2};
//     int target = 2;

//     pair<int, int> result = first_and_last_occurrence(nums, target);

//     cout << "First occurrence: " << result.first << endl;
//     cout << "Last occurrence: " << result.second << endl;

//     return 0;
// }


/*How is binary search making sure that we get the smallest index?*/
/*
Binary search ensures that we get the smallest index by following these key steps:

Middle Element Selection: In each iteration, the algorithm calculates the middle index of the search space and examines the element at that index.

Comparison: After selecting the middle element, the algorithm compares it with the target value.

Search Space Reduction: If the middle element is greater than the target value, the search is narrowed to the lower half of the array (left side of the middle element). If the middle element is smaller than the target value, the search is narrowed to the upper half of the array (right side of the middle element).

Iterative Process: The search continues iteratively, repeatedly dividing the search space in half until the target value is found or the search space is exhausted.

Index Selection: In the case where the target value is found, the algorithm ensures that it continues searching in the left half of the array (if duplicates are allowed) or that it stops searching immediately (if duplicates are not allowed), thereby ensuring that the smallest index containing the target value is found.

By consistently narrowing the search space towards the left side when encountering duplicates or when the middle element equals the target value, binary search ensures that the smallest index containing the target value is returned. This property is crucial for certain applications, such as finding the lower bound of a value in a sorted array.

*/

// lower_bound -> arr[index] >= x
// upper_bound -> arr[index] > x

//2*O(log2n)
int firstOcc(vector<int>arr, int k){

    int s=0, e=arr.size()-1;

    int temp=-1;

    while(s<=e) 

    {

        int mid = s+(e-s)/2;

        if(arr[mid] == k){

            temp = mid;

            e = mid-1;  //as fist occurence to lowwer me hi milegi

        }

        else if(arr[mid]<k) s = mid+1;

        else e = mid-1;

    }

    return temp;

}

int lastOcc(vector<int>arr, int k){

    int s=0, e=arr.size()-1;

    int temp=-1;

    while(s<=e)

    {

        int mid = s+(e-s)/2;

        if(arr[mid]==k){

            temp = mid;

            s = mid+1;  //as last occurence to upper me hi milegi

        }

        else if(arr[mid] > k){ 

            e = mid-1;

        }

        else s = mid+1;

    }

    return temp;

}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    return {firstOcc(arr, k), lastOcc(arr, k)};
}


